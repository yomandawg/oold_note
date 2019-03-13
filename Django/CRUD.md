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
pip install django.extensions ipython
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

