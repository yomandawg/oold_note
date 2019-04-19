# Django

> Python Web Framework

* MTV 구조
  * Model, Template, View

## 프로젝트 생성 및 환경 설정

1. 프로젝트 진행할 폴더 생성: `[TEST]`
2. 해당 폴더로 이동: `cd TEST`
3. 가상 환경 설정
   * `pyenv virtualenv 3.6.7 [가상환경 이름]`
   * `pyenv local [가상환경 이름]`
4. `django` 설치
   * `pip install django`
5. Django 프로젝트 test 생성
   * `django-admin startproject text .`
6. Django 서버 실행
   * `python manage.py runserver $IP:$PORT`

## 실행 코드

* zzu.li/install-pyenv
* `pyenv`와 version 관리 등 사용하기 쉽게 하는 command들

```bash
git clone https://github.com/pyenv/pyenv.git ~/.pyenv
echo 'export PYENV_ROOT="$HOME/.pyenv"' >> ~/.bashrc
echo 'export PATH="$PYENV_ROOT/bin:$PATH"' >> ~/.bashrc
echo -e 'if command -v pyenv 1>/dev/null 2>&1; then\n  eval "$(pyenv init -)"\nfi' >> ~/.bashrc
exec "$SHELL"
# pyenv --version # pyenv 1.2.9-2-g6309aaf2
git clone https://github.com/pyenv/pyenv-virtualenv.git $(pyenv root)/plugins/pyenv-virtualenv
echo 'eval "$(pyenv virtualenv-init -)"' >> ~/.bashrc
exec "$SHELL"
```

* version semantics*: major.minor.pre_release+meta

```bash
pyenv install 3.6.7
pyenv global 3.6.7
# python --version # Python 3.6.7
```

* `django` initiation

```bash
mkdir PRACTICE
cd PRACTICE
pyenv virtualenv 3.6.7 practice-venv
pyenv local practice-venv # practice-venv로 가상환경화
pip install django # 가상환경 안에만 있는 django
django-admin startproject practice . # django-admin startproject practice 하면 폴더 안에 폴더
```

---

* `django` 폴더 구조

```bash
tree . # 폴더 구조 보기
# __init__.py # django package file - 건드릴 일 없음
# settings.py # django configuration 파일
# urls.py
# wsgi.py # 배포할 때
# manage.py # python 사용용
```

* server run

```bash
python manage.py runserver $IP:$PORT
				#인자		#C9 port와 연결
```

* Settings 변경

```python
# /settings.py
ALLOWED_HOSTS = ['django-practice-sitback.c9users.io'] # 내 HOST 주소 도메인 허용

LANGUAGE_CODE = 'ko-kr' # 언어 변경

TIME_ZONE = 'Asia/Seoul' # 시간대 변경
```

* Project 구조 - `Django` project 속에 여러 applications 

```
PROJECT/
	project
	application1
	...
```

* create application

```python
python manage.py startapp pages
						#app name

# practice/settings.py
INSTALLED_APPS = [
    'django.contrib.admin',
    'django.contrib.auth',
    'django.contrib.contenttypes',
    'django.contrib.sessions',
    'django.contrib.messages',
    'django.contrib.staticfiles',
    'pages', # my app
]
```

---

## Views

> Functions

```python
### VIEW ###
# /views.py
def index(request): # @app.route('/'); def index():
    return render(request, 'index.html') # return render_template('index.html')
```

```python
### TEMPLATES ###
templates/
	index.html
```

* 특정 요청이 *router*(`url`)로 오면 거기에 대응되는 *function*(`view`)에 연결

```python
# /urls.py
from pages import views # views라는 file에서 가져옴
urlpatterns = [
    path('admin/', admin.site.urls),
    path('', views.index), # '' == '/' route
    path('ispal/<str:words>', views.ispal),
]
```

* send information

```python
def index(request):
    context = {'msg': 'hello', 'name':'John'} # 편리한 방법
    return render(request, 'index.html', context) # dict 형태로 전송
```

* Sample views

```python
urlpatterns = [
    path('admin/', admin.site.urls),
    path('', views.index),
    path('cube/<int:number>', views.cube),
    path('ispal/<str:words>', views.ispal)
]

# Cubed number
def cube(request, number):
    res = number**3
    return render(request, 'cube.html', {'res': res})

# Palindrome check
def ispal(request, words):
    res = False
    if words == words[::-1]:
        res = True
    return render(request, 'ispal.html', {'res': res})
```

---

### artii API application

* `http://artii.herokuapp.com/make?text=<text>&font=<font>`
* `pip install requests`

```python
import requests, random

# 사용자의 입력을 받을 페이지
def new(request):
    return render(request, 'new.html')

# artii API를 통해 ascii 아트로 변환하여 보여주는 페이지
def artii(request):
    # Flask에서 request.args.get
    word = requests.GET.get('word')
    fonts = requests.get('http://artii.herokuapp.com/fonts_list').text.split("\n")
    font = random.choice(fonts)
    url = 'http://artii.herokuapp.com/make?text={}&font={}'
    res = requests.get(url.format(word, font)).text
    return render(request, 'artii.html', {'res': res, 'font': font})
```

```html
<h1>ASCII Art</h1>
<form action="/artii">
    <input type="text" name="word"/>
    <input type="submit" value="Submit"/>
</form>
---
<pre>{{ res }}</pre>
{{ font }}
```

---

### PAPAGO API 번역기

```python
# 사용자로부터 단어를 입력 받아 /result로 넘겨줌
def papago(request):
    return render(request, 'papago.html')

naver_id = os.getenv('NAVER_ID')
naver_secret = os.getenv('NAVER_SECRET')
headers = {'X-Naver-Client-Id': naver_id, 'X-Naver-Client-Secret': naver_secret}
url = "https://openapi.naver.com/v1/papago/n2mt"

# PAPAGO API 검색 결과를 보여줌
def result(request):
    word = request.GET.get('word')
    data = {'source': 'en', 'target': 'ko', 'text': word}
    res = requests.post(url, headers=headers, data=data)
    res_dict = res.json() # json parse해서 넘겨줌
    res = res_dict.get('message').get('result').get('translatedText')
    return render(request, 'result.html', {'res': res})
```

```html
<h1>PAPAGO 번역기</h1>
<form action="/result">
    <input type="text" name="word"/>
    <input type="submit" value="Submit"/>
</form>
---
<h1>{{ res }}</h1>
```

---

## Virtual Environment

* environmental variable 설정

```bash
c9 ~/.bashrc
source ~/.bashrc # 가상환경이 하나 더 켜지는 셈
source deactivate # 그 환경에서 나와야함
# pyenv-virtualenv: deactivate 3.6.7/envs/practice-venv
echo $NAVER_ID # 하면 가상머신에서 환경변수 설정된 것 확인 가능
```

---

## HTML

* block
  * Jinja template
  * JS 는 body 밑에 두면 성능상 가장 빠름

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
    <title>{% block title %}{% endblock %}</title>
</head>
<body>
    {% block body %}
    {% endblock %}
    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
</body>
</html>
```

```html
{% extends 'base.html' %}

{% block title %}
장고 홈페이지
{% endblock %}

{% block body %}
<h1>First Django!</h1>
<h2>{{ name }}</h2>
<h3>{{ msg }}</h3>
{% endblock %}
```

### Static 경로

```
DB/articles/static/
	css/
		style.css
	image/
		ryan.jpg
```

```html
{% load static %}
<head>
	...
	<link rel="stylesheet" href="{% static 'css/style.css' %}">
</head>
```

```python
# settings.py
STATIC_URL = '/static/' # default 값
```

---

## Models

> Django ORM
>
> Datebase 관리

```bash
sitback:~/workspace $
mkdir DB
cd DB/
pyenv virtualenv 3.6.7 db-venv # virtualenv 만들기
pyenv local db-venv # DB/이면(local) virtualenv 자동 initiate
pip install django
django-admin startproject pracdb .
```

```bash
python manage.py startapp articles

# settings.py
ALLOWED_HOSTS = ['django-practice-sitback.c9users.io']
INSTALLED_APPS = [
    ...
    'articles' # my app
]
```

`python manage.py runserver $IP:$PORT`

```python
# articles/models.py
from django.db import models

# Create your models here.
class Article(models.Model): # SQLAlchemy: class Article(db.Model):
    # id title content
    # id 자동생성
    title = models.TextField() # CREATE TABLE articles ( title TEXT )
    content = models.TextField()
```

* models 관리내역에 올리기: `makemigrations`
  * *versioning*, 돌아갈 수 있음 - git의 commit과 같음

```bash
python manage.py makemigrations
> Migrations for 'articles':
>  articles/migrations/0001_initial.py # 새로 생긴 파일
>    - Create model Article

# articles/migrations/0001_initial.py
('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID'))
# id라는 column을 자동으로 생성함
```

* 서버를 돌릴 때마다 `db.sqlite3`파일 생기는 것 볼 수 있다.

```bash
sqlite3 db.sqlite3
sqlite> .tables # None
# 비어있는 것 확인할 수 있음
```

* 데이터를 실제 DB에 저장하는 것: `migrate`
  * git의 push와 같음

```bash
python manage.py migrate
> Applying articles.0001_initial... OK # 우리가 만든 articles table이 migrate된 것
```

```bash
sqlite3 db.sqlite3
sqlite> .tables
articles_article            auth_user_user_permissions
auth_group                  django_admin_log          
auth_group_permissions      django_content_type       
auth_permission             django_migrations         
auth_user                   django_session            
auth_user_groups   
# table 이름 articles_article 생성된 것 확인
```

``` bash
python manage.py shell
# 현재 django 환경이 load된 python shell(대화형)
>>> from articles.models import Article
>>> a = Article(title="happy", content="hacking")
# SQLAlchemy: db.session() ...
>>> a.save()

# DB 확인
>>> Article.objects.all() # SELECT * FROM articles_article;
<QuerySet [<Article: Article object (1)>]> # 현재 table에 있는 정보 record list
>>> Article.objects.first().title
'happy'

# sqlite3으로 DB 확인
sqlite3 db.sqlite3
sqlite> SELECT * FROM articles_article;
1|happy|hacking
```

```bash
# articles 0001에 대한 sql 확인
$ python manage.py sqlmigrate articles 0001
BEGIN;
--
-- Create model Article
--
CREATE TABLE "articles_article" ("id" integer NOT NULL PRIMARY KEY AUTOINCREMENT, "title" text NOT NULL, "content" text NOT NULL);
COMMIT;
```

---

## CRUD

* Create

```bash
$ python manage.py shell
>>> from articles.models import Article
# Create
>>> a = Article(title="와 여기서도 글이 써진다!!", content="장고 짱짱맨")
>>> a.save()
>>> Article.objects.create(title="hey", content="create") # 위 두줄을 하나로 합친 메서드
제목: hey, 내용: create
# 생성자 객체로 만들어서 하는 것(첫 번째 방법) 선호
```

* Read

```bash
# Read
>>> Article.objects.all()
<QuerySet [<Article: Article object (1)>, <Article: Article object (2)>]>
>>> len(Article.objects.all())
2
```

```python
# >>> Article.objects.all()
# <QuerySet [<Article: Article object (1)>, <Article: Article object (2)>]> 출력 제어
# articles/migrations/models.py
class Article(models.Model):
    ...
    def __repr__(self):
        return f"제목: {self.title}, 내용: {self.content}"
    
    def __str__(self): # print로 사용
        return f"제목: {self.title}, 내용: {self.content}"
```

```bash
$ python manage.py shell
>>> from articles.models import Article # import 다시
>>> Article.objects.all()
<QuerySet [제목: happy, 내용: hacking, 제목: 와 여기서도 글이 써진다!!, 내용: 장고 짱짱맨]>
>>> for a in Article.objects.all():
...		a # __repr__ 메서드로
...
제목: happy, 내용: hacking
제목: 와 여기서도 글이 써진다!!, 내용: 장고 짱짱맨
>>> from articles.models import Article
>>> for a in Article.objects.all():
...     print(a) # __str__ 메서드로
... 
제목: happy, 내용: hacking
제목: 와 여기서도 글이 써진다!!, 내용: 장고 짱짱맨
```

```bash
>>> Article.objects.filter(title="happy").all() # filter
<QuerySet [제목: happy, 내용: hacking]>
>>> Article.objects.filter(content="hacking").first() # filter and first
제목: happy, 내용: hacking
>>> Article.objects.filter(content="hacking").count() # count
1
>>> Article.objects.all().count() # count all
2
>>> Article.objects.get(pk=1) # by primary key
제목: happy, 내용: hacking
>>> Article.objects.get(id=1) # by id
제목: happy, 내용: hacking
>>> Article.objects.get(title="happy") # by key == filter and first
제목: happy, 내용: hacking
```

* Update

```bash
>>> a = Article.objects.get(id=1)
>>> a.content = "Thursday"
>>> a.save()
>>> Article.objects.get(id=1)
제목: happy, 내용: Thursday # 바뀐 것 확인
```

* Delete

```bash
>>> a = Article.objects.get(id=2)
>>> a.delete()
(1, {'articles.Article': 1}) # 지워지고 id값으로 1개만 남았다는 말
```

---

```bash
$ python manage.py shell
>>> from articles.models import Article
>>> a = Article(title="title test", content="content test")
>>> a.save()
>>> Article.objects.create(title="hey", content="create") # 위 두줄을 하나로 합친 것
제목: hey, 내용: create
>>> Article.objects.order_by('id').all()
<QuerySet [제목: happy, 내용: Thursday, 제목: title test, 내용: content test, 제목: hey, 내용: create]>
>>> Article.objects.order_by('-id').all() # -부호 안에 들어가있어도 된다!
<QuerySet [제목: hey, 내용: create, 제목: title test, 내용: content test, 제목: happy, 내용: Thursday]>
>>> Article.objects.all()[0] # list기 때문에 조작 가능
제목: happy, 내용: Thursday
>>> Article.objects.all()[::-1]
[제목: hey, 내용: create, 제목: title test, 내용: content test, 제목: happy, 내용: Thursday]
```

---

### Faker example

```python
# models.py
class Job(models.Model):
    name = models.TextField()
    job = models.TextField()
```

```bash
$ python manage.py makemigrations
Migrations for 'articles': # 새로운 class가 생긴 것을 감지하고 model Job을 만듦(매우 smart)
  articles/migrations/0002_job.py
    - Create model Job
```

```bash
$ python manage.py migrate # 실제 DB에 적용
Operations to perform:
  Apply all migrations: admin, articles, auth, contenttypes, sessions
Running migrations:
  Applying articles.0002_job... OK
```

```bash
$ python manage.py sqlmigrate articles 0002 # 무엇을 migrate했는지 보여줌
BEGIN;
--
-- Create model Job
--
CREATE TABLE "articles_job" ("id" integer NOT NULL PRIMARY KEY AUTOINCREMENT, "name" text NOT NULL, "job" text NOT NULL);
COMMIT;
```

```python
from django.shortcuts import render
from .models import Job # 현재 경로에서 Job import해야함
from faker import Faker

# Create your views here.
def index(request):
    return render(request, 'index.html')
    
def pastlife(request):
    return render(request, 'pastlife.html')
    
def result(request):
    name = request.GET.get('name')
    fake = Faker('ko_KR')

    person = Job.objects.filter(name=name).first()
    if person:
        job = person.job
    else:
        job = fake.job()
        person = Job(name=name, job=job)
        person.save()
    
    api_key = ''
    data = requests.get(f"http://api.giphy.com/v1/gifs/search?q={job}&api_key={api_key}&limit=1").json()
    try: image = data.get('data')[0].get('images').get('fixed_width').get('url')
    except: image = ''

    context = {'name': name, 'job': job, 'image': image}
    return render(request, 'result.html', context)
```

---

## admin 관리

`django-practice-sitback.c9users.io/admin/`

* Descriptive programming
  * descriptive frameword - Django
  * 서술해서 modeling - framework에 설명하듯이 programming

```python
# admin.py
from django.contrib import admin # 이미 지정된 template
from .models import Job

class JobAdmin(admin.ModelAdmin): # custom display
    list_display = ('name', 'job')

admin.site.register(Job, JobAdmin) # 불러올 DB와 template
```

```bash
$ python manage.py createsuperuser
사용자 이름 (leave blank to use 'ubuntu'): admin
이메일 주소: 
Password: 
Password (again): 
Error: Your passwords didn't match.
Password: qwerty123
Password (again): qwerty123
비밀번호가 너무 일상적인 단어입니다.
Bypass password validation and create user anyway? [y/N]: y
Superuser created successfully.
```

