```
* Pycharm

### venv

가상환경

뭘 하던 다 여기에

pep8 (corrections)

ctrl + alt + s

alt + f12 (f12)

console font

ctrl + D : 줄 복사

ctrl + alt + r :  manage.py@first_local >
```

### 

# Django

```
first_local/
	first_local/
	templates/
		page404 같은 default templates
	venv/
	manage.py
```



```
git init
git add . (불필요한거까지 다 add함)
rm -rf .git (git remove)

touch .gitignore
```

.gitignore

```python
# Virtual ENV
venv/

# Pycharm Auto Generated DIR
.idea/

# Python Auto Generated DIR
__pycache__/

# DB
*.sqlite3
```



```
git init
git add .
git status
```



```
python manage.py startapp board (django manage.py 랑 same)
pip install django_extensions ipython
```

```python
# first_local/settings.py
INSTALLED_APPS = [
    'django.contrib.admin',
    'django.contrib.auth',
    'django.contrib.contenttypes',
    'django.contrib.sessions',
    'django.contrib.messages',
    'django.contrib.staticfiles',
    'django_extensions',
    'board',
]

LANGUAGE_CODE = 'ko-kr'

TIME_ZONE = 'Asia/Seoul'

# InternatlizatioN
USE_I18N = True

# LocalizatioN
USE_L10N = True

# TimeZone
USE_TZ = False
```

```
touch board/urls.py
mkdir -p board/templates/board/ (directory 한번에 다만듦)
cd board/templates/board/
touch list.html detail.html new.html edit.html
cd - (뒤로가기)
```

```python
# first_local/urls.py
urlpatterns = [
    path('admin/', admin.site.urls),
    path('board/', include('board/urls'))
]
```



```python
# board/urls.py

from django.urls import path

```



```
python manage.py makemigrations
python manage.py migrate
```

```
python manage.py runserver
```





```
alias pm='python manage.py'
```





ctrl + alt + r :  manage.py@first_local >

```python
from IPython import embed

embed() # 개꿀
```



shift + shift

ctrl + g

shift + enter

shift + ctrl + arrow



`pip install pillow` for using `ImageField`

`pip install django-imagekit` for image processing





`git rm -r --cached first_local/media/` git 특정 경로 관리 해제



```bash
python manage.py shell_plus
p = Posting.objects.get(id=9)
p.image_thumbnail.url # cache 확인하면 생성
```



* Font awesome

`<link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.7.2/css/all.css" integrity="sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr" crossorigin="anonymous">`



* DB에 변화를 주변 POST else GET!



```python
# 1
posting = Posting()
posting.content = request.POST.get('content')
...
posting.save()

# 2
posting = Posting(
	content=request.POST.get('content'),
    ...
)
posting.save()

# 3
posting = Posting.objects.create(
    content=request.POST.get('content'),
    icon=request.POST.get('icon'), 
    image=request.FILES.get('image')
)
```



`python manage.py migrate [APP_NAME]` 특정 app만 migrate

`python manage.py migrate [APP_NAME] zero` 모든 migration에서 적용했던 것들 지우기 (테이블 다 날라감)





`python manage.py createsuperuser`



windows에서 sqlite3

데이터 우클릭 import db from path ...

