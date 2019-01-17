# HTML / CSS / Bootstrap APP



## GIPHY API application

> * API: Application Programming Interface
>   * set of functions and procedures allowing the creation of applications that access the features
> * SDK: Software Development Kit
>   * set of tools that can be used to develop software applications 

* **ID**: `yomandawgshit@gmail.com`

* **key**:  `ca6434XaDdudJeioOqvblYqQatskcaaY`



```python
# curl, command line
curl "http://api.giphy.com/v1/gifs/search?q=ryan+gosling&api_key=YOUR_API_KEY&limit=5"
```

`http://api.giphy.com/v1/gifs/search?q=ryan+gosling&api_key=ca6434XaDdudJeioOqvblYqQatskcaaY&limit=5`



```python
import urllib,json
data = json.loads(urllib.urlopen("http://api.giphy.com/v1/gifs/search?q=ryan+gosling&api_key=YOUR_API_KEY&limit=5").read())
print json.dumps(data, sort_keys=True, indent=4)
```



```python
import requests # encode HTTP's
from pprint import pprint as pp # python structures 예쁘게 출력

api_key = 'ca6434XaDdudJeioOqvblYqQatskcaaY'
query = 'cat'

base_url = 'http://api.giphy.com/v1/gifs/search?q={}&api_key={}&limit=5'

url = base_url.format(query, api_key)

res = requests.get(url) # gets the response
pp(res.json()) # parse by json(JavaScript Object Notation) <dict> form for easy data handling
```





## Flask

```python
from flask import Flask, render_template# 어딘가에 있는 flask.py 에서 class Flask()를 사용

app = Flask(__name__) # __init__ 건드려줌
# class Flask():
#    def __init__(self):
```

```python
@app.route('/') # decorator: app.route()에 주입함; # '/' 는 url주소
def index():
    return render_template('index.html') # templates folder에서 index.html로 나타냄


@app.route('/search')
def search():
    query = request.args.get('query') # 'query' args를 가져옴
    return render_template('search.html', query=query)
```

`flask run --host=0.0.0.0 --port=8080`

* *C9*이 bind된 **host**: `--host=0.0.0.0` **port**:  `--port=8080`
* https://giphy-sitback.c9users.io/
* **Jinja2**





## Bootstrap

```html
<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.2.1/css/bootstrap.min.css" integrity="sha384-GJzZqFGwb1QTTN6wy59ffF1BuGJpLSa9DkKMp0DgiMDm4iYMj70gZWKYbI706tWS" crossorigin="anonymous">
<script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.6/umd/popper.min.js" integrity="sha384-wHAiFfRlMFy6i5SRaxvfOCifBUQy1xHdJ/yoi7FRNXMRBu5WHdZYu1hA6ZOblgut" crossorigin="anonymous"></script>
<script src="https://stackpath.bootstrapcdn.com/bootstrap/4.2.1/js/bootstrap.min.js" integrity="sha384-B0UglyR+jN6CkvvICOB2joaf5I4l3gm9GU6Hc1og6Ls7i6U/mkkaduKaBhlAXv9k" crossorigin="anonymous"></script>
```





## Jinja

* *Template engine* 언어 for **Flask**
* like python

```jinja2
{% for jjal in jjals %} # 반복문
{{ jjals }}
{% endfor %}

{{ }} # print
```



### dry-out

> * 중복되는 코드 없애기
> * block들은 상속관계에서 override 가능

**layout.html**

```html
<body>
    {% block content %}
    	<customize>
    {% endblock %}

            
    {% include 'footer.html' %} # block 없이 그냥 로드
</body>
```

**block.html**

```html
{% extends 'layout.html' %} # <layout.html>을 붙여넣기 한다.


{% block content%}

<h1>블락페이지</h1> # customized contents

{% endblock %}
```



---

---

`sudo pip3 install requests`

`sudo pip3 install flask`

`flask run --host=0.0.0.0 --port=8080`

