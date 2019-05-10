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

$ mkdir API
$ cd API


$ pyenv virtualenv 3.6.7 api-venv 
$ pyenv local api-venv
$ pip install django==2.1.7 ipython django-extensions
$ django-admin startproject api .

$ python manage.py startapp ...
$ python manage.py migrate
$ python manage.py createsuperuser
```



#### API JSON 형태로 가져오자

* 모든 Artist 다 가져올 때: `GET 'api/artists/'`
* 특정 Artist 한 명만 가져올 때: `GET 'api/artists/1'`'
* Artist를 만들 때: `POST 'api/artists/'`
* Artist를 수정할 때: `PUT/PATCH 'api/artists/1'`
* Artist를 지울 때: `DELETE 'api/artists/1'`

```python
# api/settings.py
INSTALLED_APPS = [
    ...
    'rest_framework', # pip install djangorestframework
    'rest_framework_swagger', # pip install django-rest-swagger
    'memo', 
    'corsheaders', # pip install django-cors-
]

MIDDLEWARE = [
    'corsheaders.middleware.CorsMiddleware', # pip install django-cors-headers
]

CORS_ORIGIN_ALLOW_ALL = True
```

```python
# api/urls.py
from django.urls import path, include
from django.conf.urls import url
from rest_framework_swagger.views import get_swagger_view

schema_view = get_swagger_view(title='movies API')

urlpatterns = [
    ...
    url(r'^$', schema_view),
    path('api/v1/', include('memo.urls')),
]
```

```python
# memo/serializer.py
from rest_framework import serializers
from .models import Memo

class MemoSerializer(serializers.ModelSerializer):
    class Meta:
        model = Memo
        fields = ['content',]
```

```python
# memo/urls.py
from django.urls import path
from . import views

app_name = 'memo'

urlpatterns = [
    path('memos/create/', views.memo_create),
    path('memos/', views.memo_list),
]
```

```python
# memo/views.py
from django.shortcuts import render
from rest_framework.response import Response
from rest_framework.decorators import api_view
from .serializer import MemoSerializer
from .models import Memo

@api_view(['POST'])
def memo_create(request):
    serializer = MemoSerializer(data=request.data)
    if serializer.is_valid():
        serializer.save()
        return Response(serializer.data)

@api_view(['GET'])
def memo_list(request):
    memos = Memo.objects.all()
    serializer = MemoSerializer(memos, many=True)
    return Response(serializer.data)
```

```python
# memo/models.py
from django.db import models

class Memo(models.Model):
    content = models.TextField()
```

# Stick Notes

## Django Rest Framework

1. Django rest framework 로 api 서버를 만든다

2. `content` 필드 1개를 가지고 있는 `Memo` 모델을 만든다.

3. POST 요청으로 Memo 를 create 할 수 있다.

   - POST http://localhost:8000/api/v1/memos/

4. GET 요청으로 모든 Memo 를 read 할 수 있다.

   - GET http://localhost:8000/api/v1/memos/

## Vue.js

1. textarea 태그와 Vue 의 data 인 `content` 를 양방향 바인딩한다.

2. `created` life cycle 에서 axios 로 위 api 서버에서 memos 를 불러온 뒤 Vue 의 data 인 memos 에 바인딩한다.

3. submit 버튼이 눌리면 axios 로 위 api 서버로 `content` 의 내용을 작성한뒤 응답받은 memo 를 Vue 의 memos 에 push 한다.

4. memo 가 작성될때마다 textarea 의 값은 초기화된다.