# 2019.03.20

> 나중에 AWS 서버 쓸 것 같음. (레드헷 / 우분투)
>
> 1. ssh로 서버 직접 접근해서 작업 (vim)
> 2. windows 에 vm (vagrant) 깔고 거기서 작업 > github > (ssh로 서버 접근) aws server 에서 pull

tag. DevOps Wunderlist Trello

[![IMG_0001]()](https://github.com/AutumnSky92/TIL/blob/master/TIL/TIL_Django%26DB.md)

#### Create a new workspace > Rails Tutorial

- RAM이 좀 더 잡혀있음
- shell (zzu.li/install_pyenv)

```
$ sudo apt-get update

$ sudo apt-get install -y make build-essential libssl-dev zlib1g-dev libbz2-dev libreadline-dev libsqlite3-dev wget curl llvm libncurses5-dev libncursesw5-dev xz-utils tk-dev
```

> sudo : 관리자 권한 apt-get : 우분투의 쵸코 package management tool

<http://zzu.li/install-pyenv>

```
git clone https://github.com/pyenv/pyenv.git ~/.pyenv
echo 'export PYENV_ROOT="$HOME/.pyenv"' >> ~/.bashrc
echo 'export PATH="$PYENV_ROOT/bin:$PATH"' >> ~/.bashrc
echo -e 'if command -v pyenv 1>/dev/null 2>&1; then\n  eval "$(pyenv init -)"\nfi' >> ~/.bashrc
exec "$SHELL"

##### pyenv --version:pyenv 1.2.9-19-g7d02b246


git clone https://github.com/pyenv/pyenv-virtualenv.git $(pyenv root)/plugins/pyenv-virtualenv
echo 'eval "$(pyenv virtualenv-init -)"' >> ~/.bashrc
exec "$SHELL"

##### cat ~/.bashrc
##### eval : 스크립트 동작시키는 함수

pyenv install 3.6.7
pyenv global 3.6.7

$ mkdir NEWPROJECT
$ cd NEWPROJECT


$ pyenv virtualenv 3.6.7 todo-venv 
$ pyenv local todo-venv
$ pip install django ipython django-extensions
$ django-admin startproject todoapp .

$ python manage.py startapp todos
$ python manage.py migrate
$ python manage.py createsuperuser
```

> mr-auto > ml-auto : 왼쪽에 붙이기 > 오른쪽에 붙이기
>
> markup : ovenapp. balsamiq

auth 인증, 권한부여 : 본질적인 코어 기능은 장고가 이미 가지고 있음

### 로그인 관련 app을 따로 만들어보자

#### users 앱 생성

```
$ python manage.py startapp users
```

> no module... : install을 알려주면 해결
>
> python manage.py startapp users
>
> 기본 규약은 프레임 워크가 알아서 해줌(비밀번호 암호화 DB저장)
>
> Secure Hash Alogorithm (made by NSA)
>
> Cryptographic + Hash function

#### app 구성

- login
- logout
- profile
- register

#### Hash Function

> python hashlib

[![IMG_0002]()](https://github.com/AutumnSky92/TIL/blob/master/TIL/TIL_Django%26DB.md)

#### 로그인 & 로그아웃 함수

- django 가 제공하는 login() 함수 & logout() 함수

```
# users/views.py
from django.contrib.auth import authenticate, login, logout
```

- 제공되는 것들을 사용하는 이유 > 기본적인 보안 문제 or 오류 발생을 막는 처리가 되어 있음 + 간편함
- 자세한 내용은 users/views.py

> HTTP = Stateless
>
> - 상태가 없음



#### LOGIN

```python
from django.shortcuts import render, redirect
from django.contrib.auth import authenticate, login, logout
from django.contrib.auth.forms import UserCreationForm
from django.contrib import messages


# /users/login/ 
def login_user(request):
    if request.method == "POST":
        # login == user 인증
        # > 1. request에 담긴 정보 (username, password)
        # > 2. DB에 user가 있고, 정보가 일치 하는지 확인
        username = request.POST.get('username')
        password = request.POST.get('password')
        
        # 1. 유저를 검증한다.
        # - DB에 해당하는 username을 가진 유저가 있고,
        # - 해당 유저의 password가 입력된 값과 같은지
        user = authenticate(request, username=username, password=password)
        # pseudo code
        # username으로 찾아서 hash 변환하고 password 비교하고 맞으면 유저 객체를 반환
        # 아닌경우 None 을 반환
        
        # 2. 유저를 로그인시킨다.
        # 서버에 해당 유저가 유효한 유저임을 세션에 저장
        if user is not None:
            login(request, user)
            # 유저에게 성공적으로 로그인이 되었다고 알려줌
            messages.success(request, "로그인이 되었습니다.")
            return redirect('todos:home')
        else:
            # 유저에게 로그인이 실패했다고 알려줌
            messages.success(request, "로그인에 실패했습니다.")
            return redirect('users:login')
    else:
        return render(request, 'users/login.html')
   
        
def logout_user(request):
    # 유저를 logout 시킨다.
    # > 세션에서 유저를 지운다.
    logout(request)
    messages.success(request, "로그아웃 되었습니다.")
    return redirect('users:login')
    
    
def profile(request):
    # 유저 정보
    return render(request, 'users/profile.html')
    
def register(request):
    if request.method == "POST":
        form = UserCreationForm(request.POST)
        if form.is_valid():
            form.save()
            login(request, form.instance)
            messages.success(request, "로그인이 되었습니다.")
            return redirect('todos:home')
    else:
        form = UserCreationForm()
        return render(request, 'users/register.html', {
            'form': form
        })
```



#### 메세지 출력

```
# settings.py
MESSAGE_STORAGE = 'django.contrib.messages.storage.session.SessionStorage'
# views.py
messages.success(request, "로그인에 실패했습니다.")
# request에 message를 담아서 보내는 형식
return redirect('users:login')
<!-- base.html -->
<!-- 메세지를 보여줌 -->
{% if messages %}
<div class="alert alert-warning alert-dismissible fade show" role="alert">
    {% for message in messages %}
    {{ message }}
    {% endfor%}
    <button type="button" class="close" data-dismiss="alert" aria-label="Close">
        <span aria-hidden="true">&times;</span>
    </button>
</div>
{% endif %}
```

- 내일은? : 유저와 to do list를 1:N으로 연결하는 과정

# 2019.03.21

- model form & form class
- 시간이 남으면 aws 가입까지

## todos

### DB 설계

- content / completed(Flaging) / user_id(ForeignKey)
- User는 auth가 만들어주고, 관리해주는데 눈에는 안보임(패키징되어있음)
- Todos 와 User와 연결
- 1:N (1 > N_set 으로 한번에 뽑기, N > 1 접근하기 하는 방식이 가능하다는 걸 다시 한번 고려하자)

## shouts

- django-forms

  - forms.py 생성
    - models.py 에서 정의한 DB의 정보를 가져다 사용하기 때문에 여기서 알려주기만 하면 됨
  - Form Class 혹은 ModelForm Class를 사용하는 이유는 어제 로그인관련 함수들을 쓴 이유와 같음
    - 간편 + 유효성 검사

  ```
  # shouts/forms.py
  # Form Class?
  from django import forms
  from .models import Shout
  
  
  # model이름 + Form : 관례
  # model에 기반하여, 장고가만들어주는 form
  class ShoutForm(forms.Form):
      title = forms.CharField()
      content = forms.CharField()
      
      
  # ModelForm Class?
  # - Form Class 보다 간편하게 사용가능
  # - views.py에서 코드를 더 짧게 가능
  # - 속성값을 주는 것도 가능
  class ShoutModelForm(forms.ModelForm):
      class Meta:
          model = Shout
          # fields 값을 알려주기
          fields = ['title', 'content']
          # 속성값 넣기
          widgets = {
              'title': forms.TextInput(
                  attrs = {
                      'class': 'form-control',
                      'placeholder': '제목을 입력해주세요.',
                  }
              ),
              'content': forms.Textarea(
                  attrs = {
                      'class': 'form-control',
                      'placeholder': '내용을 입력해주세요.',
                  }
              ),
          }
  ```

  ```
  <!-- form 구성이 자동으로 됨 -->
  {% block body %}
  <form method="POST" action="{% url 'shouts:update' form.instance.id %}">
      {% csrf_token %}
      {{ form.as_p }}
      <input type="submit"/>
  </form>
  {% endblock %}
  ```

> 꿀팁
>
> python `in` operator는 set으로 바꾸고 쓰면 빠름
>
> html에서 {% debug %}로 다양한 값을 확인 가능