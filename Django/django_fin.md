### BDD &rarr; TDD

> Behavior Driven Development &rarr; Test Driven Development

1. 무엇을 하는 서비스
   - 사용자가 사진 upload, interact
2. 사용자 어떻게 서비스를 활용하는지
   - Mock-up = 유저가 서비스를 어떻게 볼지
     - 사용자의 행위(Behavior)가 Test Case
3. 데이터 모델링



## Django

* pyenv settings

`https://gist.github.com/djohnkang/7d7ba4854b505fe42236fccd8ee9788c`

```bash
git clone https://github.com/pyenv/pyenv.git ~/.pyenv
echo 'export PYENV_ROOT="$HOME/.pyenv"' >> ~/.bashrc
echo 'export PATH="$PYENV_ROOT/bin:$PATH"' >> ~/.bashrc
echo -e 'if command -v pyenv 1>/dev/null 2>&1; then\n  eval "$(pyenv init -)"\nfi' >> ~/.bashrc
exec "$SHELL"

git clone https://github.com/pyenv/pyenv-virtualenv.git $(pyenv root)/plugins/pyenv-virtualenv
echo 'eval "$(pyenv virtualenv-init -)"' >> ~/.bashrc
exec "$SHELL"
```

`pyenv --version` >> `pyenv 1.2.10-5-g78cecd20`

```bash
pyenv install 3.6.7
pyenv global 3.6.7 # 3.6.7 버젼 사용
```

```bash
mkdir INSTAGRAM
cd INSTAGRAM
pyenv virtualenv 3.6.7 insta-venv
pyenv local insta-venv
# pip intall django # install latest version
pip install django==2.1.7
```

gitignore easy create

- `gitignore.io/api/django`



```bash
django-admin startproject instagram .
```

```python
# instagram/settings.py

ALLOWED_HOSTS = ['sitback-sitback.c9users.io']

INSTALLED_APPS = [
    ...
    'posts',
    'bootstrap4',
]

TEMPLATES = [
    {
        'DIRS': [os.path.join(BASE_DIR, 'templates')],
    }
]

LANGUAGE_CODE = 'ko-kr'

TIME_ZONE = 'Asia/Seoul'
```

`python manage.py runserver $IP:$PORT`

`python manage.py createsuperuser`



```bash
python manage.py startapp posts
```

```python
# posts/models.py

from django.db import models

# Create your models here.
class Post(models.Model):
    content = models.CharField(max_length=150)
    
    def __str__(self):
        return self.content
```

```bash
python manage.py makemigrations
python manage.py migrate
```

```python
#posts/admin.py

from .models import Post

admin.site.register(Post)
```





## Bootstrap

```
INSTAGRAM/ #최상위 폴더
	templates/
		base.html
	instagram/
	posts/
	...
	manage.py
```

```html
#templates/base.html

<!doctype html>
<html lang="en">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
    
    <!--FontAwesome CSS-->
    <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.8.1/css/all.css" integrity="sha384-50oBUHEmvpQ+1lW4y57PTFmhCaXp0ML5d60M1M7uH2+nqUivzIebhndOJK28anvf" crossorigin="anonymous">
    
    <title>Instagram{% block title %}{% endblock %}</title>
  </head>
  <body>
    {% include 'nav.html' %}
    
    {% block body %}
    {% endblock %}

    <!-- Optional JavaScript -->
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
  </body>
</html>
```



```html
#templates/navbar.html

<nav class="navbar navbar-expand-lg navbar-light bg-light">
  <a class="navbar-brand" href="#"><i class="fab fa-instagram"></i> Instagram</a>
  <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarNav" aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
    <span class="navbar-toggler-icon"></span>
  </button>
  <div class="collapse navbar-collapse" id="navbarNav">
    <ul class="navbar-nav">
      <li class="nav-item active">
        <a class="nav-link" href="#">Home <span class="sr-only">(current)</span></a>
      </li>
      <li class="nav-item">
        <a class="nav-link" href="#">Features</a>
      </li>
      <li class="nav-item">
        <a class="nav-link" href="#">Pricing</a>
      </li>
      <li class="nav-item">
        <a class="nav-link disabled" href="#" tabindex="-1" aria-disabled="true">Disabled</a>
      </li>
    </ul>
  </div>
</nav>
```



```python
#instagram/urls.py

from django.contrib import admin
from django.urls import path, include

urlpatterns = [
    path('admin/', admin.site.urls),
    path('posts/', include('posts.urls')),
]
```



```python
#posts/urls.py

from django.urls import path
from . import views

app_name = "posts"

urlpatterns = [
    path('create/', views.create, name="create"),
    path('', views.list, name="list"),
]
```



```python
#posts/views.py

from django.shortcuts import render, redirect
from .forms import PostForm
from .models import Post

# Create your views here.
def create(request):
    if request.method == "POST":
        # 작성된 post를 DB에 적용
        form = PostForm(request.POST)
        if form.is_valid():
            form.save()
            return redirect('posts:list')
    else: # GET
        # post를 작성하는 form을 보여줌
        form = PostForm()
        return render(request, 'posts/create.html', {'form': form})

def list(request):
    posts = Post.objects.all()
    return render(request, 'posts/list.html', {'posts': posts})
    
def detail(request, post_id):
    post = Post.objects.get(id=post_id)
    return render(request, 'posts/detail.html', {'post': post})
    
def update(request, post_id):
    p = Post.objects.get(id=post_id)
    if request.method == "POST":
        # 작성된 post를 DB에 적용
        form = PostForm(request.POST, instance=p)
        if form.is_valid():
            form.save()
            return redirect('posts:list')
    else: # GET
        # post를 작성하는 form을 보여줌
        form = PostForm(instance=p)
        return render(request, 'posts/create.html', {'form': form})
    
def delete(request, post_id):
    p = Post.objects.get(id=post_id)
    p.delete()
    return redirect('posts:list')
    
```



```html
#posts/create.html

{% extends 'base.html' %}

{% block body %}
<form method="POST">
  <!-- 모델 폼 -->
  {{ form }}
</form>
{% endblock %}
```



```python
#posts/forms.py

from django import forms
from .models import Post

# Post라는 모델을 조작할 수 있는 PostForm 정의
class PostForm(forms.ModelForm):
    # 1. 어떤 input 필드를 가지는지
    content = forms.CharField(label="content", widget=forms.Textarea())
    
    # 2. 해당 input 필드의 속성을 추가 & 어떤 모델을 조작할지
    class Meta:
        model = Post
        fields = ['content']
```



`pip install django-bootstrap4` - Django 위에 Bootstrap 연동

- package 설치 후 `settings.py`에서 꼭 알려줘
- `{% load bootstrap4 %}`



```html
#posts/create.html

{% extends 'base.html' %}

{% load bootstrap4 %}

{% block body %}
<form method="POST">
  <!-- 모델 폼 -->
  {% csrf_token %}
  {% bootstrap_form form %}
  <button type="submit"></button>
</form>
{% endblock %}
```



```html
#posts/list.html

{% extends 'base.html' %}

{% block body %}
  <div class="row justify-content-center">
    {% for post in posts %}
      <div class="card" style="width: 40rem;">
        <img src="https://picsum.photos/200/200/?random" class="card-img-top" alt="...">
        <div class="card-body">
          <p class="card-text">{{ post.content }}</p>
          <a href="{% url 'posts:update' post.id %}" class="btn btn-success">수정</a>
          <a href="{% url 'posts:delete' post.id %}" class="btn btn-danger">삭제</a>
        </div>
      </div>
    {% endfor %}
  </div>
{% endblock %}
```



* CDN (cloud node)
* RDS



#### Django Image Processing

`pip install pillow` - python imaging library

```python
#posts/models.py

class Post(models.Model):
    content = models.CharField(max_length=150)
    image = models.ImageField(blank=True)
    
    def __str__(self):
        return self.content
```

```python
#posts/forms.py

class PostForm(forms.ModelForm):
    # 1. 어떤 input 필드를 가지는지
    content = forms.CharField(
        label="내용", 
        widget=forms.Textarea(attrs={
            'placeholder': '오늘은 무엇을 하셨나요?'
        })
    )
    
    # 2. 해당 input 필드의 속성을 추가 & 어떤 모델을 조작할지
    class Meta:
        model = Post
        fields = ['content', 'image']
```

image(file) 넘어가지 못하는 문제:

```html
#posts/create.html

{% block body %}
<form method="POST" enctype='multipart/form-data'> # 여러 정보를 따로 가져옴
  <!-- 모델 폼 -->
  {% csrf_token %}
  {% bootstrap_form form %}
  <button type="submit" class="btn btn-primary">업로드</button>
</form>
{% endblock %}
```

파일이 어디에 저장되는지 설정해야함

```python
#instagram/settings.py

# 미디어 파일들이 불릴 url
MEDIA_URL = '/media/' # media가 어디에 있고, 찾으려면 어디로 가야한다
# 실제 저장장소
MEDIA_ROOT = os.path.join(BASE_DIR, 'media')
```

url 경로 설정해야함

```python
#instagram/urls.py

from django.conf import settings # Django가 settings 따로 관리함 - 사용자는 직접 접근 안해도 돼, 앱이 방대해졌을 때 용이, 세세한 수정에 다른 코드들이 영향받지 않게 하기 위해
# 모든 설정은 django.conf에 기록됨
from django.conf.urls.static import static
urlpatterns += static(settings.MEDIA_URL, document_root=settings.MEDIA_ROOT)
```

```html
#posts/list.html

{% block body %}
  <div class="row justify-content-center">
    {% for post in posts %}
      <div class="card" style="width: 40rem;">
        <img src="{{ post.image.url }}" class="card-img-top" alt="...">
        <div class="card-body">
          <p class="card-text">{{ post.content }}</p>
          <a href="{% url 'posts:update' post.id %}" class="btn btn-success">수정</a>
          <a href="{% url 'posts:delete' post.id %}" class="btn btn-danger">삭제</a>
        </div>
      </div>
    {% endfor %}
  </div>
{% endblock %}
```





#### Post와 유저 연결

```python
#posts/models.py

from django.conf import settings

# Create your models here.
class Post(models.Model):
    content = models.CharField(max_length=150)
    image = models.ImageField(blank=True)
    # user = models.ForeignKey(User, on_delete=models.CASCADE) #User 폼 변경하려면 상속받아서 다르게 짜야함
    user = models.ForeignKey(settings.AUTH_USER_MODEL, on_delete=models.CASCADE)
```

`python manage.py makemigrations`

```bash
# default 'user'
Select an option: 1
>>> 1 # choose user(id=1)
```

`python manage.py migrate`



```html
#posts/list.html

{% block body %}
  <div class="row justify-content-center">
    {% for post in posts %}
      <div class="card-header">
        <span>{{ post.user }}</span>
      </div>
      <div class="card" style="width: 40rem;">
        <img src="{{ post.image.url }}" class="card-img-top" alt="...">
        <div class="card-body">
          <p class="card-text">{{ post.content }}</p>
          
          <!-- 작성자만 수정/삭제 가능 -->
          {% if post.user == request.user %}
            <a href="{% url 'posts:update' post.id %}" class="btn btn-success">수정</a>
            <a href="{% url 'posts:delete' post.id %}" class="btn btn-danger">삭제</a>
          {% endif %}
          
        </div>
      </div>
    {% endfor %}
  </div>
{% endblock %}
```

```python
#posts/views.py

def update(request, post_id):
    post = get_object_or_404(Post, pk=post_id)
    if post.user != request.user:
        return redirect('post:list')
    if request.method == "POST":
        # 실제 DB에 수정 반영
        form = PostForm(request.POST, instance=post)
        if form.is_valid():
            form.save()
            return redirect('posts:list')
    else:
        form = PostForm(instance=post)
        return render(request, 'posts/update.html', {'form': form})
    
    
def delete(request, post_id):
    post = get_object_or_404(Post, pk=post_id)
    if post.user != request.user:
        return redirect('posts:list')
    post.delete()
    return redirect('posts:list')
```



-----

## M:M

```python
#posts/models.py

class Post(models.Model):
    content = models.CharField(max_length=150)
    image = models.ImageField(blank=True)
    # user = models.ForeignKey(User, on_delete=models.CASCADE) #User 폼 변경하려면 상속받아서 다르게 짜야함
    user = models.ForeignKey(settings.AUTH_USER_MODEL, on_delete=models.CASCADE) # user foreign_key를 불러오므로 user_id 키가 있을 것
    like_users = models.ManyToManyField(settings.AUTH_USER_MODEL, related_name="like_posts", blank=True) # user와 M:M 관계
    # M:M은 쌍방향이라 어느쪽에 테이블을 만들어도 상관 없음; users에 넣어도 됨(초기 설계단계에서 설정) # related_name에 양쪽 다 조회할 수 있게끔 이름 설정
    # users like 가 문법적으로 맞지만 users model을 접근하기가 일단 어렵기 때문에 이렇게 함
```

모델 변경 &rarr; `migrate`



`python manage.py sqlmigrate posts 0004` - django가 sql로 뭔짓 했는지 보여줌

```bash
BEGIN;
--
-- Add field like_users to post
--
CREATE TABLE "posts_post_like_users" ("id" integer NOT NULL PRIMARY KEY AUTOINCREMENT, "post_id" integer NOT NULL REFERENCES "posts_post" ("id") DEFERRABLE INITIALLY DEFERRED, "user_id" integer NOT NULL REFERENCES "auth_user" ("id") DEFERRABLE INITIALLY DEFERRED);
CREATE UNIQUE INDEX "posts_post_like_users_post_id_user_id_372014ef_uniq" ON "posts_post_like_users" ("post_id", "user_id");
CREATE INDEX "posts_post_like_users_post_id_5876c897" ON "posts_post_like_users" ("post_id");
CREATE INDEX "posts_post_like_users_user_id_8d849ce2" ON "posts_post_like_users" ("user_id");
COMMIT;
```



`pip install django_extensions`

```python
#posts/settings.py

INSTALLED_APPS = [
    ...
    'django_extensions',
]
```

`python manage.py shell_plus`

```shell
>>> Post.objects.all()
<QuerySet [<Post: adfgdfg>]>
>>> post = Post.objects.first()
>>> post
<Post: adfgdfg>
>>> User.objects.all()
<QuerySet [<User: admin>]>
>>> post.like_users
<django.db.models.fields.related_descriptors.create_forward_many_to_many_manager.<locals>.ManyRelatedManager object at 0x7fc722f065c0>
>>> user = User.objects.first()
>>> user.like_posts.all()
<QuerySet []> # user이 like한 Post가 없음
>>> user.like_posts.add(post) # user가 post를 like
>>> user.like_posts.all()
<QuerySet [<Post: adfgdfg>]>
```

다른 유저 추가

```shell
>>> User.objects.all()
<QuerySet [<User: admin>, <User: yoman@yoman.com>]>
>>> ahley = User.objects.last()
>>> ahley
<User: yoman@yoman.com>
>>> ahley.like_posts.all()
<QuerySet []>
>>> ahley.like_posts.add(Post.objects.first())
>>> ahley.like_posts.all()
<QuerySet [<Post: adfgdfg>]>

>>> john = User.objects.first()
>>> john
<User: admin>
>>> john.post_set.all() # john이 쓴 모든 post
<QuerySet [<Post: adfgdfg>]>
>>> john.post_set.first().like_users.all() # john이 쓴 첫번째 post를 like한 모든 사람
# ORM을 통해서 왔다갔다 조회 가능
<QuerySet [<User: admin>, <User: yoman@yoman.com>]> # queryset으로 유저 리스트가 나옴
>>> exit()
```



```python
#posts/views.py
from django.contrib.auth.decorators import login_required
# login_required
# 1. 유저가 로그인 안했으면, 로그인창으로 보냄 - default = accounts
# 2. "https://sitback-sitback.c9users.io/accounts/login/?next=/posts/1/like"
# next:로그인 되는 순간 like 하게 만들겠다. url 끝난다음에 어디로 가는지 고려

def create(request):
    if request.method == "POST":
        # 작성된 post를 DB에 적용
        form = PostForm(request.POST, request.FILES)
        if form.is_valid():
            post = form.save(commit=False) # auth 기능으로 추가
            post.user = request.user
            post.save()
            return redirect('posts:list')
    else: # GET
        # post를 작성하는 form을 보여줌
        form = PostForm()
        return render(request, 'posts/create.html', {'form': form})

@login_required(redirect_field_name="posts:list") # session에 로그인이 안돼있으면 막음
def like(request, post_id):
    # 1. like를 추가할 포스트를 가져옴
    post = get_object_or_404(Post, id=post_id)
    # post = Post.objects.get(id=post_id)
    
    # 2. 만약 유저가 해당 post를 이미 like 했다면,
    #       like를 제거하고,
    #    아니면,
    #       like를 추가한다.
    if request.user in post.like_users.all(): # 유저가 post.like_users.all() -> queryset 리스트 안에 있으면,
        post.like_users.remove(request.user) # like 해제
    else:
        post.like_users.add(request.user)
        
    return redirect('posts:list')
```

```python
#posts/urls.py
urlpatterns = [
    ...
    path('<int:post_id>/like', views.like, name="like"), # url엔 post_id만 넘겨주고, user관한 정보는 view에서 처리
]
```

```html
#post/list.html

<!-- 좋아요 버튼 추가 -->
<div class="card-body">
    <a href="{% url 'posts:like' post.id %}">
        <!-- 해당 유저가 like를 했으면, -->
        {% if user in post.like_users.all %}
        <i class="fas fa-heart"></i>
        <!--아니면-->
        {% else %}
        <i class="far fa-heart"></i>
        {% endif %}
    </a>
    <p class="card-text">
        {{ post.like_users.count }}명이 좋아합니다.
    </p>
</div>
```



## 로그인 구현

```html
#templates/nav.html

<nav class="navbar navbar-expand-lg navbar-light bg-light">
  <a class="navbar-brand" href="#"><i class="fab fa-instagram"></i> Instagram</a>
  <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarNav" aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
    <span class="navbar-toggler-icon"></span>
  </button>
  <div class="collapse navbar-collapse" id="navbarNav">
    <ul class="navbar-nav ml-auto">
      <!-- 만약 로그인이 되어 있으면 -->
      {% if user.is_authenticated %}
        <li class="nav-item">
          <a class="nav-link disabled" href="#" tabindex="-1" aria-disabled="true">{{ user.username }}</a>
        </li>
        <li class="nav-item">
          <a class="nav-link" href="{% url 'accounts:logout' %}">로그아웃</a>
        </li>
      
      <!-- 아니면 -->
      {% else %}
      <li class="nav-item">
        <a class="nav-link" href="{% url 'accounts:login' %}">로그인</a>
      </li>
      <li class="nav-item">
        <a class="nav-link" href="{% url 'accounts:signup' %}">회원가입</a>
      </li>
      
      {% endif %}
    </ul>
  </div>
</nav>
```

`python manage.py startapp accounts`

```python
# settings.py
INSTALLED_APPS = [
    'accounts',
]
```

```python
# urls.py 메인 urls 관문
urlpatterns = [
    ...
    path('accounts/', include('accounts.urls')),
]
```

```python
# accounts/urls.py
app_name = "accounts"

urlpatterns = [
    path('login/', vies.login, name="login"),
    path('logout/', views.logout, name="logout"),
    path('signup/', views.signup, name="signup"),
]
```

* **next** 핸들링: `@login_required`

```python
# accounts/views.py
from django.contrib.auth.forms import AuthenticationForm
from django.contrib.auth import login as auth_login # django에서 가져와 씀
from django.contrib.auth import logout as auth_logout

def login(request):
    if request.method == "POST":
        # POST: 실제 로그인(세션에 유저 정보 추가)
        form = AuthenticationForm(request, request.POST)
        if form.is_valid():
            auth_login(request, form.get_user())
            return redirect(request.GET.get('next') or 'posts:list')
            # (parameter GET에서 받았을 때 'next'가 있으면 '/posts/13/like/') or 'posts:list'
            # next= 정의되어 있으면, 해당하는 url로 리다이렉트
            # else: 'posts:list'
    else:
        # GET: 로그인 정보 입력
        form = AuthenticationForm()
        
    return render(request, 'accounts/login.html', {'form': form})
    

def logout(request):
    auth_logout(request)
    return redirect('posts:list')
```

```html
# accounts/login.html

{% extends 'base.html' %}
{% load bootstrap4 %}

{% block body %}
<h1 class="text-center">로그인</h1>
<form method="POST">
  {% csrf_token %}
  {% bootstrap_form form %}
  <button class="btn btn-primary">로그인</button>
</form>
{% endblock %}
```





## 회원가입

```html
# accounts/signup.html

{% extends 'base.html' %}
{% load bootstrap4 %}

{% block body %}
<h1 class="text-center">회원가입</h1>
<form method="POST">
  {% csrf_token %}
  {% bootstrap_form form %}
  <button class="btn btn-primary">회원가입</button>
</form>
{% endblock %}
```

```python
# accounts/views.py
from django.contrib.auth.forms import UserCreationForm

def signup(request):
    if request.method == "POST":
        # POST: 유저 등록
        form = UserCreationForm(request.POST) # UserCreationForm이 알아서 column에 넣어주고
        if form.is_valid():
            user = form.save()
            # auth_login(request, form.get_user()) 로그인과 달리 form 형식 달라서 이거 안됨
            auth_login(request, user) # signup 후 바로 로그인
            redirect('posts:list')
    else:
        # GET: 유저 정보 입력
        form = UserCreationForm()
        
    return render(request, 'accounts/signup.html', {'form': form})
```



## 프로필 페이지

* 유저들의 정보가 들어가 있는 *people* 페이지

```python
#instagram/urls.py
from accounts import views as accounts_views

urlpatterns = [
    ...
    path('<str:username>/', accounts_views.people, name="people")
]
```

```python
#accounts/views.py
from django.contrib.auth import get_user_model

def people(request, username):
    # 사용자에 대한 정보
    people = get_object_or_404(get_user_model(), username=username) # 모델과 keyword 인자로 가능
    # 1. settings.AUTH_USER_MODEL - 이건 views를 쓰기 힘듦
    # 2. get_user_model() 실제 user클래스를 바로 리턴시켜줌 - 되도록이면 이거 쓰자
    # 3. User (django.contrib.auth.models에 들어가있는) 그냥 가져오기 - 안쓰는게 좋아
    return render(request, 'accounts/people.html', {'people': people})
```

```html
#accounts/people.html
{% extends 'base.html' %}

{% block body %}
<div class="container">
  <h1>{{ people.username }}</h1>
  <div class="row">
    {% for post in people.post_set.all %}
    <div class="col-4">
      <img src="{{ post.image.url }}" class="img-fluid">
    </div>
    {% endfor %}
  </div>
</div>
{% endblock %}
```





## Comment

```html
#posts/list.html
<!-- 로그인한 상태면 -->
{% if user.is_authenticated %}
<!--댓글 기능 -->
<div class="card-body">
    <form method="POST" action="{% url 'posts:comment' post.id %}">
        {% csrf_token %}
        {% bootstrap_form form %}
        <button type="submit" class="btn btn-info">댓글쓰기</button>
    </form>
</div>
<div class="card-body">
    {% for comment in post.comment_set.all %}
    <div class="card-text">
        <strong>{{ comment.user.username }}</strong> {{ comment.content }}
    </div>
    <!-- else와 유사한 비어있을 때 조건문 empty -->
    {% empty %}
    <div>댓글이 없습니다.</div>
    {% endfor %}
</div>
{% endif %}
```

```python
#posts/models.py
class Comment(models.Model):
    content = models.CharField(max_length=100)
    # 두 개의 Foreign key를 갖게됨
    post = models.ForeignKey(Post, on_delete=models.CASCADE) # 어떤 모델을 참조하고 있는지
    user = models.ForeignKey(settings.AUTH_USER_MODEL, on_delete=models.CASCADE)
    
    def __str__(self):
        return self.content
```

```python
#posts/forms.py
from .models import Comment
class CommentForm(forms.ModelForm):
    class Meta:
        model = Comment
        fields = ['content']
```

`python manage.py makemigrations` `python manage.py migrate`

```python
#posts/urls.py
...
path('<int:post_id>/comment/create/', views.create_comment, name="comment"),
```

```python
#posts/views.py
from .forms import CommentForm
from django.views.decoreators.http import require_POST

@login_required
@require_POST # POST 말고는 차단
def create_comment(request, post_id):
    # Comment를 만드는 로직
    post = get_object_or_404(Post, pk=post_id)
    form = CommentForm(request.POST)
    if form.is_valid():
        comment = form.save(commit=False)
        comment.user = request.user
        # comment.post_id = post_id # 객체로 하거나 ORM에 맡기거나 둘중에 하나만 하는게 관례
        comment.post = post
        comment.save()
    return redirect('posts:list')
```



## User 강화

- 유저 정보 변경
- 프로필 추가

```python
#accounts/views.py
# 회원 정보 변경(편집 & 반영)
def update(request):
    if request.method == "POST":
        user_change_form = CustomUserChangeForm(request.POST, instance=request.user)
        if user_change_form.is_valid():
            user = user_change_form.save() # save된 객체를 return함
            return redirect('people', user.username)
    else: # GET: 지금 로그인한 유저의 현재 정보를 띄워주는 form
        user_change_form = CustomUserChangeForm(instance=request.user)
        # 현재 로그인된 정보 but 이것만 출력하면 너무 많아 -> 원하는 정보만 보게 수정해야함
        # password_change_form = PasswordChangeForm(request.user)
        # context = {'user_change_form': user_change_form, 'password_change_form': password_change_form} # 서로 다른 페이지로 만들거다
        context = {'user_change_form': user_change_form}
        return render(request, 'accounts/update.html', context)
```

```python
#accounts/forms.py
class CustomUserChangeForm(UserChangeForm): # 그냥 UserChangeForm에서 모듈화로 customize
    class Meta:
        model = get_user_model()
        fields = ['username', 'email', 'first_name', 'last_name'] # 어느 필드만 보여주고 싶다 선택 가능
```

```python
#accounts/urls.py
path('update/', views.update, name="update"),
path('delete/', views.delete, name="delete"),
```

```html
#accounts/people.html
{% extends 'base.html' %}

{% block body %}
<div class="container">
  <h1>{{ people.username }}</h1>
  <p>{{ people.first_name }} {{ people.last_name }}</p>
  {% if user == people %}
  <a class="btn btn-info" href="{% url 'accounts:update' %}">회원 정보 변경</a>
  <a class="btn btn-danger" href="{% url 'accounts:delete' %}">회원 탈퇴</a>
  {% endif %}
  <div class="row">
    {% for post in people.post_set.all %}
    <div class="col-4">
      <img src="{{ post.image.url }}" class="img-fluid">
    </div>
    {% endfor %}
  </div>
</div>
{% endblock %}
```



## 탈퇴

```python
#accounts/views.py
# 회원 탈퇴
def delete(request):
    if request.method == "POST":
        request.user.delete()
    return render(request, 'accounts/delete.html')
```

```html
#accounts/delete.html
```



## 비밀번호 변경

```python
#accounts/views.py
# 비밀번호 변경
def password(request):
    if request.method == "POST":
        password_change_form = PasswordChangeForm(request.user, request.POST)
        if password_change_form.is_valid():
            user = password_change_form.save() # 그냥 이렇게 하면 session 로그아웃됨 -> login상태 유지하려면?
            update_session_auth_hash(request, user) # auth hash 자동 업데이트 - 로그인 유지
            return redirect('people', user.username)
    else:
        password_change_form = PasswordChangeForm(request.user)
        return render(request, 'accounts/password.html', {'password_change_form': password_change_form})
```

```html
#accounts/password.html
{% extends 'base.html' %}
{% load bootstrap4 %}

{% block body %}
<h1 class="text-center">비밀번호 변경</h1>
<form method="POST">
  {% csrf_token %}
  {% bootstrap_form password_change_form %}
  <button class="btn btn-primary">수정</button>
</form>
{% endblock %}
```

* Hashing

  - username+password+salt string concatation (통합 정보)

  * 남겨진 cookie를 확인해서 유저가 로긴상태인지 아닌지 `session 공간`에서 확인
  * session엔 유저의 통합정보가 관리됨
  * 유저가 request할 때 cookie와, 정보를 보내면 -> 그 값을 session에서 찾는다
  * 만약 비번 바꾸면 username+password+salt 에서 password가 바껴서 hash값이 바뀐다
    * hash값이 reload돼야해!
    * 이 값을 억지로 바꿔줘야해 `update_session_auth_hash`
      * 세션에 있는 auth hash를 바꿔줘



* HTTP: 통신 규약
  * cookie가 필요한 이유: 서로 누군지 밝히기 위해
  * (과거에 설계됐을 때, 서버 작으니까)서버쪽에서 최소한의 정보를 쥐고있고, client쪽에서 많은 정보(쿠키)를 가지고 있어
    * request 보낼 때, cookie를 갖고 있는 사람은 다 그전 유저라고 생각함
  * html header이 작은 이유
  * 시크릿모드 -> 서버에서 아무 cookie도 받지 않음
  * 쿠키를 복사하면 그사람인척 할 수 있다
  * 취약한 사이트는 쿠키만 조작하면 로그인한척 할 수 있음





## Follow

* M:N 
  * User가 User를 팔로우





