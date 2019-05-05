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
# api/urls.py
```



```python
# musics/serializer.py
```

