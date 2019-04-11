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

