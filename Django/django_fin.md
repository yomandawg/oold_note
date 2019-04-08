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

class Post(models.Model):
    content = CharField(max_length=150)
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

    <title>Instagram - {% block title %}{% endblock %}</title>
  </head>
  <body>
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

