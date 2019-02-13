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

## 실행 코드

* `zzu.li/install-pyenv`
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
django-admin startproject practice .
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
ALLOWED_HOSTS = ['django-practice-sitback.c9users.io'] # 내 HOST 주소

LANGUAGE_CODE = 'ko-kr' # 언어 변경

TIME_ZONE = 'Asia/Seoul' # 시간대 변경
```

* Project 구조 - `Django` project 속에 여러 applications 

```
PROJECT/
	project/
		application1
		application2
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
    path('', views.index) # '' == '/' route
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

