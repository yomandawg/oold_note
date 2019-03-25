# 2019.02.13

django

M - T - V(매우 중요)

Model : 데이터(베이스) 관리

Template : 사용자가 보는 화면 ()

View : 중간 관리자 (Control)

## Template & View

### c9 환경에서의 Django

<https://gist.github.com/djohnkang/7d7ba4854b505fe42236fccd8ee9788c>

pyenv 설치 : Legacy Code 관리를 위해 사용

Semantic Versioning (ex. BREAKING.FEATURE.FIX)

#### New Workspace (Virtual)

```
$ git clone https://github.com/pyenv/pyenv.git ~/.pyenv
$ echo 'export PYENV_ROOT="$HOME/.pyenv"' >> ~/.bashrc
$ echo 'export PATH="$PYENV_ROOT/bin:$PATH"' >> ~/.bashrc
$ echo -e 'if command -v pyenv 1>/dev/null 2>&1; then\n  eval "$(pyenv init -)"\nfi' >> ~/.bashrc
$ exec "$SHELL"
$ pyenv --version

$ git clone https://github.com/pyenv/pyenv-virtualenv.git $(pyenv root)/plugins/pyenv-virtualenv
$ echo 'eval "$(pyenv virtualenv-init -)"' >> ~/.bashrc
$ exec "$SHELL"

$ pyenv global 3.6.7
```

#### New Project

```
### 새로운 프로젝트 디렉토리 이름은 대문자로!
$ mkdir NEWPROJECT
$ cd NEWPROJECT


### 가상환경 생성
$ pyenv virtualenv 3.6.7 <새로운 가상환경 이름>-venv 

### 자동으로 가상환경이 로드 되도록 설정
$ pyenv local newproject-venv

### 장고 설치
$ pip install django

### 마지막에 점을 꼭 찍어서 경로를 분명히 해주자
$ django-admin startproject <새로운 프로젝트 이름 :소문자로 하자..헷갈림> . #점#
$ pip list
$ tree .
```

- 파일 구성

```
.
├── manage.py 			// 편집할 일 거의 없음
└── practice
    ├── __init__.py 	// 편집할 일 거의 없음
    ├── settings.py
    ├── urls.py
    └── wsgi.py			// 배포할 때 사용
```

- 프로젝트 생성 후에 웹 주소를 설정해준다.

```
# in settings.py
# 웹 주소 설정
ALLOWED_HOSTS = ["django-practice-ssafycm.c9users.io"]
### https://는 제외
```

#### 서버 구동

```
$ python manage.py runserver $IP:$PORT
// $IP:$PORT 는 c9 용
```

리로드가 자동임 ㄷㄷ

internationalization : i18n

#### 앱 생성

- 명령

```
$ python manage.py startapp pages
```

- 구성

```
.
├── db.sqlite3
├── manage.py
├── pages
│   ├── __init__.py				// 거의 안씀
│   ├── admin.py				// 관리자용 페이지에서 활용
│   ├── apps.py					// 거의 안씀
│   ├── migrations
│   │   └── __init__.py			// 거의 안씀
│   ├── models.py
│   ├── tests.py
│   └── views.py
```

- 앱을 만들고 나면 알려줘야함

```
# in settings.py
INSTALLED_APPS = [
	# .
    # .
    # .
    # 추가 : 끝나는 요소에 ,를 꼭 붙여야함
    # Django에서는 이렇게 쓰자 (trailing comma)
    'pages',
]
```

### views.py & urls.py

- Flask와의 차이점

​	1) route > urls.py 에 views를 import 하고 경로와 이름을 알려줌

​	2) request > 함수의 인자로

​	3) render > 짧게, request를 함께

> Flask html > jinja
>
> Django html > 거의 비슷

1. index

   ```
   # in views.py
   def index(request):
       return render(request, 'index.html')
   ```

2. isval

   ```
   
   ```

3. variable routing

   ```
   # in views.py
   
   def cube(request,number):
       # 사용자로부터 url로 입력받은 값을 세제곱합니다.
       result = number ** 3
       return render(request, 'cube.html', {'result':result})
       
   def ispal(request,string):
       result = False
       if string == string[::-1]:
           result = True
       data = {'result': result}
       return render(request, 'ispal.html', data)
   ```

   ```
   # in urls.py
   
   urlpatterns = [
       path('cube/<int:number>', views.cube),
       path('ispal/<str:string>', views.ispal),
   ]
   ```

##### 환경변수

```
$ c9 ~/.bashrc

$ source ~/.bashrc

### 가상환경이 중복으로 생성 > 하나를 꺼주면 됨

$ source deactivate
```

# 2019.02.14

> Django에서 선언한 Model을 실제 DB에 반영하는 과정을 무엇이라고 하는가?
>
> 모델의 필드를 정의할 때 CharField는 필수로 들어가야하는 인자가 존재한다. 무엇인가?
>
> Django에서 동작하는 모든 명령을 대화식 Python 쉘에서 시험할 수 있는 명령어를 작성하세요.
>
> Post라는 이름의 모델은 CharField로 정해진 title과 CharField로 정해진 content가 필드로 정의 되어있다. 제목은 자신의 이름, 내용은 자신의 이메일 정보가 들어간 Post를 만드는 코드를 작성하세요.

Flask > jinja : layout.html

Django Template Language : base.html

- 문법은 거의 동일

## Model

### Django ORM

DB의 반영 과정 (Migrations)

1. moels.py에서 정의 & 알려주는 과정
2. Migrate : db에 적용

- 정의

```
# in models.py
from django.db import models

# Create your models here.
class Article(models.Model):
    
# 알아서 table name 생성 ,id도 자동임
```

#### makemigrations

```
$ python manage.py makemigrations
```

#### migrate

```
$ python manage.py migrate
```

#### shell

- runtime 데이터를 관리

```
$ python manage.py shell
------------------------------------------
>>> from articles.models import Article

### Create	
>>> a = Article(title="happy", content="hacking")
## 상태 변경 요청 / 테이블에 추가
>>> a.save()
## 한줄적기
>>> Article.objects.create(title='t2',content='c2')

### Read
>>> Article.objects.all()
# <QuerySet [<Article: Article object (1)>]>
## objects > query (in sqlalchemy)
## all() > SELECT * 느낌 (query set은 list랑 매우 비슷)
>>> Article.objects.first().title
# 'happy'

>>> Article.objects.filter(title="happy").all()
## filter > WHERE 느낌
>>> Article.objects.filter(title="happy").first()
## query set의 첫번째 요소

>>> Article.objects.all().count()
>>> Article.objects.get(pk=1)
>>> Article.objects.get(id=1)
>>> Article.objects.get(title="happy")

### Update
>>> a = Article.objects.get(pk=1)
>>> a.content = "Thursday"
>>> a.save()

### Delete
>>> a = Article.objects.get(id=2)
>>> a.delete()

### order : 간편하게 DB에서 ordering 하자(단, DB환경에 따라 성능이 다름)
>>> a = Article.objects.order_by('id')
>>> a = Article.objects.order_by('-id')
>>> Article.objects.all()[1:2]

>>> exit()
```

#### sqlmigrate

- 출력

```
$ python manage.py sqlmigrate articles 0001
# BEGIN;
~~~~~~~~~~
```

#### createsuperuser

```
$ python manage.py createsuperuser
```

# 2019.02.15

#### static folder 적용하기

/templates 와 같은 디렉토리에서 폴더 생성 (/static)

/static 에 static 자료들 위치 (.css , imgs)

```
<!-- Django는 디폴트로 주소를 갖고 있기 때문에 base.html에만 이렇게 추가해주자 -->

<!-- static을 로드하고 -->
{% load static %}

<!DOCTYPE html>
<html lang="en">
<head>
    <!-- 링크로 위치를 알려준다 -->
	<link rel="stylesheet" href="{% static 'css/style.css' %}">
<head>
```

# 2019.02.20

## CRUD 복습

### Create

```
## 두줄적기
# a라는 객체 생성
a = Article(title="happy", content="hacking")
a.save()
# 저장

## 한줄적기
Article.objects.create(title="happy",content="hacking")
```

### Read

```
all_contents = Article.objects.all()
title = Article.objects.first().title
```

### Update

```
a = Article.objects.get(pk=1)
# a = Article.objects.get(id=1)
a.content = "Thursday"
a.save()
```

### Delete

```
a = Article.objects.get(id=2)
a.delete()
```

## Django 환경 개선

- django , ipython, django_extensions 설치

```
$ pip install django ipython django-extensions
```

- template \ articles \ index.html
- render의 default root : template
- sql 콘솔 켜기
- extensions 설치를 알려줘야함

```
# in settings.py
INSTALLED_APPS = [
    'django.contrib.admin',
    'django.contrib.auth',
    'django.contrib.contenttypes',
    'django.contrib.sessions',
    'django.contrib.messages',
    'django.contrib.staticfiles',
    'django_extensions',
    'pages',
    'articles',
]
$ python manage.py dbshell
```

- python shell > ipython & django_extensions 을 설치해서 syntex highlighting이 됨

```
$ python manage.py shell
```

- Auto Load : import를 자동으로 해줌 > 앞으로 이걸 쓰자

```
$ python manage.py shell_plus
```

## 실습

### RESTful API

- "URL에 동사를 빼자"

naming 규칙을 잘 지키자

url 링크 쓸 때 앞 뒤로 '/' 를 붙여주자 (파일 디렉토리는 아님)

Read

| /articles/   | list   |
| ------------ | ------ |
| /articles/1/ | detail |

Create

| /articles/new/    | new    |
| ----------------- | ------ |
| /articles/create/ | create |

Update

| /articles/1/edit/   | edit   |
| ------------------- | ------ |
| /articles/1/update/ | update |

Delete

| /articles/1/delete/ | delete |
| ------------------- | ------ |
|                     |        |

### 대장 문지기(urls.py)의 서브 문지기 만들기

```
# in global urls.py
from django.contrib import admin
from django.urls import path, include
from articles import views

urlpatterns = [
    path('admin/', admin.site.urls),
    # 반복되는 부분을 분류해서 관리할 수 있음
    path('articles/', include('articles.urls')),
]
# in sub urls.py
from django.urls import path
from . import views

urlpatterns = [
    path('', views.index),
]
```

### POST 방식

- form action : 경로의 앞 뒤로 '/' 를 잘 써주자

  ```
  <form action = "/articles/create/" method = "POST">
  ```

- CSRF

  - 사이트에 접속중인 사용자인가? 를 확인하는 token을 관리해야함.
  - Django가 토큰을 발급 / 관리.

  ```
  <form action = "/articles/create/" method = "POST">
  	{% csrf_token %}
  </form>
  ```

- views.py

  ```
  def create(request):
      # DB에 저장
      title = request.POST.get('title')
      content = request.POST.get('content')
      articles = Article(title = title, content = content)
      articles.save()
      
      return redirect('/articles/')
  ```

### Django 스럽게 URL을 처리하자

```
urlpatterns = [
    path('', views.index, name="index"),
    path('new/', views.new, name="new"),
    path('<int:article_id>/', views.detail, name="detail"),
]
```

- hard code 된 url들은 변경할 경우가 많음.

```
<a href="{% url 'new' %}">새 글 쓰기</a>
<!-- variable routing : 넣고싶은 정보를 차례대로 입력 -->
<a href="{% url 'detail' article.id %}">{{ article.title }}</a>
```

- views.py

```
def create(request):
    # DB에 저장
    title = request.POST.get('title')
    content = request.POST.get('content')
    article = Article(title = title, content = content)
    article.save()
    
    # return redirect('/articles/')
    return redirect('detail', article.id)
```

- 장고는 모든 templates 폴더를 동일한 레벨로 탐색한다. (INSTALLED_APPS 순서)

  - 많이 공유하는 template 은 프로젝트 폴더 바로 밑에 생성(관례)

  ```
  # in settings.py
  # pwd
  TEMPLATES = [
      {
          'BACKEND': 'django.template.backends.django.DjangoTemplates',
          # DIRS 수정
          'DIRS': [os.path.join(BASE_DIR,'board','template')],
          # os.path.join > os 경로에 맞게 구성해줌(window환경에서도 가능하도록)
          'APP_DIRS': True,
          'OPTIONS': {
              'context_processors': [
                  'django.template.context_processors.debug',
                  'django.template.context_processors.request',
                  'django.contrib.auth.context_processors.auth',
                  'django.contrib.messages.context_processors.messages',
              ],
          },
      },
  ]
  ```

- app의 templates은 같은 이름의 하위 폴더를 하나 더 만들어서 거기에 넣어두자

# 2019.02.21

## 데이터 베이스 관계

### 1:1 관계

- 혼인
- 개인-주민번호

### 1:N 관계

- 1 to many
- has_many - belongs_to
- 학급 - 학생
- 게시글 - 댓글
- 유저 - 게시글
- 영화 - 리뷰

### M:N 관계

- many to many
- 수강신청 (수업 - 학생) (1:N - N:1)

### 관계없음

## 1:N 실습

- **N** 쪽에서 Foreign Key(**1** 의 PK)를 사용하여 **1** 에 접근가능

```
# in models.py

class Comment(models.Model):
    content = models.TextField()
    # ForeignKey(어디에 속한지, 속한 데이터가 삭제되면 어떤 액션을 취할지)
    # CASCADE : 함께 삭제
    article = models.ForeignKey(Article, on_delete=models.CASCADE)
article = Article.objects.first()

comment = Comment(content="첫번째 글의 첫번째 댓글입니다.",article=article_id)
# id 요소에 객체 자체를 집어 넣어도 ㄱㅊ
comment = Comment(content="첫번째 글의 첫번째 댓글입니다.",article=article)


# Django ORM의 강력함

# id도 알아서 만들어주고!
Comment.objects.first().article_id

# 연결된 자료의 탐색도 간편!
Comment.objects.first().article
# 다음과 같은 문장
# Article.objects.get(pk=Comment.objecs.first().article_id)

Comment.objects.first().article.title
Comment.objects.first().article.content
Comment.objects.filter(article_id=1).all()

# 1 쪽에서도 N 쪽으로 탐색 가능
Article.objects.first().comment_set.all()
# >>> 직접 filter을 통해 N의 자료에 접근하는 것보다 훨씬 간편한 경우도 있기 때문에 HTML 문서에서도 쉽게 활용 가능!
# Django Template Language 에서는 all() > all 이렇게 쓰던데.. 이유가?
```

- 추가

```
article = models.ForeignKey(Article, on_delete=models.CASCADE, related_name="comments")
```

​	- 1 > N 접근시 : _set 이 아닌 지정한 이름으로 사용가능

- Django Template Language

```
{% for a in article.comments.all reversed %}
{{ a.content }}
{% endfor %}
```

# 2019.03.13

## Django Project in Local (Pycharm)

- New Progject - Django
- `python manage.py startapp <appname>`

### 환경설정

- PyCharm pro install

  - Customize
    - BashSupport (install)
    - plugin - gitignore / material theme

- .gitignore

  ```
  # Virtual ENV
  venv/
  
  # Pycharm Auto Generated DIR
  .idea/
  
  # Python Auto Generated DIR
  __pycache__/
  
  # DB
  *.sqlite3
  ```

- 유효성 검사

- git

  - `mkdir -p` : 하위 디렉토리 생성
  - `cd -` : 뒤로가기

```
from IPython import embed

embed()
# 일시정지 디버깅 느낌
```

- pycharm 단축키
  - shift + Enter : 다음 행으로 Enter
  - Alt + Enter : 수정 항목 확인
  - ctrl + alt + R : manage.py Mode
  - ctrl + D : 행 복사&붙여넣기
  - ctrl + G : 행 이동
  - shift + shift : 파일 열기(이동)
  - html ( for + tab / if + tab / block + tab) : HTML 자동완성
  - ctrl + alt + L : 자동 줄 맞춤
  - ctrl+ Shift + 방향키(up, down) : 행 복붙 이동
  - Alt + F12 : 터미널창

HTTP 상태 코드 처리하기

```
article = get_object_or_404(Article, id=article_id)
# TODO : 
# FIXME : 
```

DB에 영향이 있으면 POST로 만든다 생각하자

### RESTful API

- "URL에 동사를 빼자"
- "복수형 명사"

# 2019.03.14

> ### thin controller fat model

## SNS app

- settings .py (global)

```
INSTALLED_APPS = [
    .
    .
    sns,
]
.
.
MEDIA_URL = '/media/'
MEDIA_ROOT = os.path.join(BASE_DIR, 'media')
# MEDIA : 장고 권장 사용자 컨벤션
```

- urls.py (global)

```
​```
.
.
​```
from django.conf.urls.static import static
from django.conf import settings

.
.
# Dev level 에서는 꼭 사용해야함. (DEBUG=True)
urlpatterns += static(settings.MEDIA_URL, document_root=settings.MEDIA_URL)
# DEBUG=False 일 경우 static은 빈 문자열 반환
```

> git add . && git commit -m 'typo'
>
> git add . ; git commit -m 'typo'
>
> mkdir -p sns/templates/sns
>
> touch base.html list.html detail.html
>
> pycharm 단축키 : <https://lalwr.blogspot.com/2018/04/intellij.html>

- models.py

```
from django.db import models


class Posting(models.Model):
    content = models.TextField(default='')
    icon = models.CharField(max_length=20, default='')
    # MEDIA/posting/2019/03/14 : 차라리 이렇게 경로를 구체화하는 편이 성능 괜찮
    image = models.ImageField(blank=True, upload_to='postings/%Y%m%d')
    # Python null & blank
    created_at = models.DateTimeField(auto_now_add=True)
    updated_at = models.DateTimeField(auto_now=True)

    def __str__(self):
        return f'{self.id}: {self.content[:20]}'
```

> pip install pillow : image file 용?

- admin.py

```
from django.contrib import admin
from .models import Posting


# admin page 에서 직접 수정할 필요가 없기 때문에 따로 명시를 해야 보임
class PostingModelAdmin(admin.ModelAdmin):
    # 개별 화면에서 확인만 가능
    readonly_fields = ('created_at', 'updated_at')
    # 리스트에서 보여질 Column 목록 설정
    list_display = ('id', 'content', 'created_at', 'updated_at')
    # 클릭 가능 Column 목록 설정
    list_display_links = ('id', 'content')


admin.site.register(Posting, PostingModelAdmin)
```

#### image resizing

- `$ pip install django-imagekit`
- settings.py

```
INSTALLED_APPS = [
    'imagekit',
    .
    .
]
```

> git commit -m "finish Posting Modeling"
>
> git rm -r --cached media/
>
> 폴더를 git 관리에서만 지움

#### Thumbnail

- models.py

```
class Posting(models.Model):
    image_thumbnail = ImageSpecField(
        source='image',
        processors=[
            ResizeToFit(width=320, upscale=False)
        ],
        format='JPEG',
        options={
            'quality': 60
        },
    )
```

- ob.image_thumbnail.url 을 해야 CACHE 생성 (migrate 불필요 > 호출이 됐을 때에만 생성)

- Create 방법 3가지

  ```
  #1
  posting = Posting()
  posting.content = request.POST.get('content')
  ...
  posting.save()
  
  #2
  posting = Posting(
      content=request.POST.get('content')
      ...
  )
  posting.save()
  
  #3 : save()가 필요없음
  posting = Posting.objects.create(
      content=request.POST.get('content'),
      icon=request.POST.get('icon'),
      image=request.FILES.get('image'),
  )
  ```

- migrate sns zero : migrate 한거 다 날릴수 있음.

- [github 코드](https://github.com/eduyu)

- [font awesome](https://fontawesome.com/)

> Duck-typing : "사용 방식이 비슷하면 그걸로 됐다. 그냥 사용하자" 개념

Pycharm에는 DB import 기능이 있음(sqlite3 명령어 불필요)

> c + tab : comment

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