# Django Application

> **Server on**: `python manage.py runserver $IP:$PORT`

### App settings

```bash
# bash
mkdir BOARD
cd BOARD
pyenv virtualenv 3.6.7 board-venv
pyenv local board-venv
# pip install django
# pip install django ipython # jupyter에서 쓰는 python
# pip install django_extensions
pip install django ipython django_extensions # 여러 packages 한번에 깔기
django-admin startproject board .
python manage.py startapp articles
```

```python
# board/settings.py
ALLOWED_HOSTS = ['django-practice-sitback.c9users.io']

INSTALLED_APPS = [
	...
    'django_extensions', # we installed this
    'articles',
]

LANGUAGE_CODE = 'ko-kr'

TIME_ZONE = 'Asia/Seoul'
```

```python
# board/urls.py
from articles import views

urlpatterns = [
    ...
    path('', views.home),
]
```

```python
# articles/views
def home(request):
    return render(request, 'articles/index.html')
```

#### add directory

```bash
articles/
	templates/
		articles/ # put html files inside <app_name> template directory
			index.html
```

---

### Database

```python
# articles/models.py
class Article(models.Model):
    title = models.TextField()
    content = models.TextField()
    
    def __repr__(self):
        return f"<{self.id}, {self.title} : {self.content}>"
        
    def __str__(self): # for print
        return f"<{self.id}, {self.title} : {self.content}>"
```

```bash
python manage.py makemigrations
python manage.py sqlmigrate articles 0001 # migration 내용을 sql문으로 출력
BEGIN;
--
-- Create model Article
--
CREATE TABLE "articles_article" ("id" integer NOT NULL PRIMARY KEY AUTOINCREMENT, "title" text NOT NULL, "content" text NOT NULL);
COMMIT;
python manage.py migrate # db.sqlite3 파일에 적용됨
```

```bash
sqlite3 db.sqlite3 # control db by sqlite3 console
```

```bash
python manage.py dbshell # control view db by django db shell
sqlite> .tables # view tables
sqlite> .exit # end
```

```python
python manage.py shell # 대화형(interactive) python shell
# jupyter version of python shell: ipython (with syntax highlite +@)
# different from regular python shell prompt '>>>', ORM shell
In [1]: from articles.models import Article
In [2]: article = Article(title="제목테스트", content="ㅋㅋㅋ")                     
In [3]: article.save()                                                             
In [4]: Article.objects.first()                                                     
Out[4]: <1, 제목테스트 : ㅋㅋㅋ>
In [5]: exit()
```

```python
python manage.py shell_plus # 알아서 import 해줘서 import 없이 편하게 shell 사용
In [1]: Article.objects.all()
Out[1]: <QuerySet [<1, 제목테스트 : ㅋㅋㅋ>]>
In [2]: Article.objects.all()[0].title
Out[2]: '제목테스트'
In [3]: Article.objects.all()[0].content
Out[3]: 'ㅋㅋㅋ'
In [4]: Article.objects.all()[0].id
Out[4]: 1
```

#### 표준 CRUD URL

> *RESTful.API* for standard control of web service

* Read
  * `/articles/`: list
  * `/articles/1`: detail
* Create
  * `/articles/new`: new (작성)
  * `/articles/create`: create (database 저장)
* Update
  * `/articles/1/edit`: edit
  * `/articles/1/update`: update
* Delete
  * `/articles/1/delete`: delete

---

### Sub-URL

* Main URL: `board/urls.py`
* Sub-URL: `articles/urls.py`
  * url 공통부분 처리 용이

```python
# articles/urls.py
from django.urls import path
from . import views

urlpatterns = [
    path('', views.index, name="index"), # name: url alias
    path('new/', views.new, name="new"),
    path('create/', views.create, name="create"),
    path('<int:article_id>/', views.detail, name="detail"),
    path('<int:article_id>/edit/', views.edit, name="edit"),
    path('<int:article_id>/update/', views.update, name="update"),
    path('<int:article_id>/delete/', views.delete, name="delete"),
]
```

```python
# board/urls.py
from django.urls import path, include

urlpatterns = [
    ...
    path('articles/', include('articles.urls')), 
    # include(): 'articles/' 가 붙으면 sub-url로 연결
    # 'articles/' 공통부분 뒷부분 처리 용이
]
```

```python
# articles/views.py
from django.shortcuts import render, redirect
from .models import Article

def index(request):
    # DB에 저장된 articles 불러와 보여줌
    articles = Article.objects.all().order_by('-id') # list 형태 뒤집어서
    context = {
        'articles': articles,
    }
    return render(request, 'articles/index.html', context)
    
def new(request):
    return render(request, 'articles/new.html')
    
def create(request):
    # DB에 저장
    title = request.POST.get('title') # get parameters by POST method
    content = request.POST.get('content')
    article = Article(title=title, content=content)
    article.save()
    return redirect('detail', article.id) # redirect는 alias name + 인자

def detail(request, article_id):
    # id를 통해 해당하는 글을 찾아 보여줌
    article = Article.objects.get(id=article_id)
    context = {
        'article': article
    }
    return render(request, 'articles/detail.html', context)

def edit(request, article_id):
    article = Article.objects.get(id=article_id)
    context = {
        'article': article,
    }
    return render(request, 'articles/edit.html', context)

def update(request, article_id):
    a = Article.objects.get(id=article_id)
    a.title = request.POST.get('title')
    a.content = request.POST.get('content')
    a.save()
    return redirect('detail', article_id)

def delete(request, article_id):
    a = Article.objects.get(id=article_id)
    a.delete()
    return redirect('index')
```

```
articles/
	templates/
		articles/
			index.html
			new.html
			detail.html
```

```html
index.html
<h1>게시판</h1>
<a href="{% url 'new' %}">새 글 쓰기</a> <!-- call url alias name -->

<table>
    <tr>
        <th>번호</th>
        <th>제목</th>
        <th>수정</th>
        <th>삭제</th>
    </tr>
    {% for article in articles %}
    <tr>
        <td>{{ article.id }}</td>
        <td><a href="{% url 'detail' article.id %}">{{ article.title }}</a></td>
        <td><a href="{% url 'edit' article.id %}">[수정]</a></td>
        <td><a href="{% url 'delete' article.id %}">[삭제]</a></td>
    </tr>
    {% endfor %}
</table>
```

```html
new.html
<h1>게시글 작성</h1>
<!--POST로 보낼 때는 action '/'로 닫아줘야함-->
<form action="{% url 'create' %}" method="POST"> 
    제목: <input type="text" name="title"/>
    내용: <input type="text" name="content"/>
    <input type="submit" value="Submit"/>
    {% csrf_token %} <!-- Django CSRF token -->
</form>
```

```html
detail.html
<h2>{{ article.id}}번 글</h2>
<h1>{{ article.title }}</h1>
<h2>{{ article.content }}</h2>

<a href="{% url 'index' %}">글 목록</a>
<a href="{% url 'edit' article.id %}">[수정]</a>
<a href="{% url 'delete' article.id  %}">[삭제]</a>
```

```html
edit.html
<h1>{{ article.id }}번 글 수정</h1>

<form action="{% url 'update' article.id %}" method="POST">
    제목: <input type="text" value="{{ article.title }}" name="title"/>
    내용: <input type="text" value="{{ article.content }}" name="content"/>
    <input type="submit" value="수정 완료"/>
    {% csrf_token %}
</form>

<a href="{% url 'detail' article.id %}">돌아가기</a>
```

#### Hacking a GET method

```python
# hack.py
import requests
from time import sleep
url = "django-practice-sitback.c9users.io"
title = "Don't use"
content = "GET for DB"
url = f'http://{url}/articles/create/?title={title}&content={content}'

while True:
    sleep(5) # 5초마다 DB get
    requests.get(url)
```

* `GET`은 조회할 때 사용하는 method

#### Cross-site Request Forgery (CSRF)

* Django는 보안을 위해서 *CSRF token* 발급
  * POST할 때, token이 일치하지 않을 경우 차단
  * `{% csrf_token %}` inside `form`
    * page source: `<input type="hidden" name="csrfmiddlewaretoken" value="lRDH7mo7DBouBQXfahCqXUJFwSaNCMb2gPq6hMmLNWQJNqXlqvMCIRh3s7yQDeDr">`
  * browser이 cookie를 받을 수 있어야 함
  * still able to create bypass CSRF token for hacking
    * block from simple hacks

#### URL Alias

* `path('new/', views.new, name="new")`: name for url alias
* `<a href="{% url 'new' %}">`: call url alias name
* `<a href="{% url 'detail' article.id %}">`: 동적으로 들어오는 variable routing
  * 변수 여러개면 순서대로
* `redirect('index')`: `redirect`는 alias name만 적어주면 됨
  *  `redirect('detail', article_id):` 동적 인자

---

### App 분리

* Create new app

```bash
python manage.py startapp pages
```

```python
# board/settings.py
INSTALLED_APPS = [
    ...
    'pages',
]
```

```python
# board/urls.py
from pages import views
urlpatterns = [
    ...
    path('', views.home),
]
```

```
pages/
	templates/
		home.html
```

```python
# pages/views.py
def home(request):
    return render(request, 'home.html') # Django는 모든 templates 폴더를 동등한 레벨로 찾음
```

* Django는 첫 번째 마주하는 `<any_app>/templates/home.html`을 불러옴

```python
# board/settings.py
INSTALLED_APPS = [
    ...
    'pages',
    'articles',
]
# app 순서 바꿔서 해결 가능
```

```
pages/
	templates/
		pages/home.html # app directory 경로 설정해서 해결 가능
```

```python
# pages/views.py
def home(request):
    return render(request, 'pages/home.html') # app directory 경로 설정
```

* base template extend 사용 용이

```
articles/
	templates/
		base.html # base template
		articles
```

* 하지만 중립 template는 한 app에 넣어놓으면 이상해!

```
board/ # Project Folder
	templates/ # 전역 templates로 생각
		home.html # base template
```

* 관례적으로 Project folder 안에 전역 `templates`
* 하지만 Django에서 templates는 app folder에서만 찾기 때문에 직접 알려줘야 함

```python
# board/settings.py
BASE_DIR = os.path.dirname(os.path.dirname(os.path.abspath(__file__))) # 현재 경로

TEMPLATES = [
    {
        ...
        'DIRS': [os.path.join(BASE_DIR, 'board','templates')], # <pwd> 전체 경로
    },
]
```

#### os.path.join()

```python
# BASE_DIR os.path.join() example
python manage.py shell_plus
In [1]: import os
In [2]: os.path.join('/', 'django', 'join', 'test')
Out[2]: '/django/join/test' # '\', '/'에 상관없이 os에서 폴더 경로 이어준다
```

#### Templates 구조

```python
BOARD/
	board/ # project folder
    	templates/ # base templates
    articles/
    	templates/
        	articles/ # articles templates
    pages/
    	templates/
        	pages/ # pages templates
```

---

### Database Model Altering

> Model 변경하기
>
> ORM smart functioning

```python
# articles/models.py
class Article(models.Model):
    ...
    context = models.TextField() # content -> context 바꾸고싶으면?
    ...
```

```bash
python manage.py makemigrations # models 바뀌면 물어봐줌
> Did you rename article.content to article.context (a TextField)? [y/N]
> Migrations for 'articles':
>   articles/migrations/0002_auto_20190220_1431.py # next migration number
>     - Rename field content on article to context
python manage.py migrate # 바뀐 models를 migrate(commit)하면 기존 db 최적화시켜줌
> Operations to perform:
>   Apply all migrations: admin, articles, auth, contenttypes, sessions
> Running migrations:
>   Applying articles.0002_auto_20190220_1431... OK
python manage.py sqlmigrate articles 0002 # migration 내용을 sql문으로 출력
> BEGIN;
> --
> -- Rename field content on article to context
> --
> ALTER TABLE "articles_article" RENAME TO "articles_article__old";
> CREATE TABLE "articles_article" ("id" integer NOT NULL PRIMARY KEY AUTOINCREMENT, > "context" text NOT NULL, "title" text NOT NULL);
> INSERT INTO "articles_article" ("id", "title", "context") SELECT "id", "title", ?> "content" FROM "articles_article__old";
> DROP TABLE "articles_article__old";
> COMMIT;
```

