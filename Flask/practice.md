-------------

### Local에서

`pip install flask`

`flask run`

http://127.0.0.1:5000/

localhost:5000

--------------



`sudo pip3 install flask`

```python
from flask import Flask

app = Flask(__name__) # Flask()의 instance 만들기
# __name__ 써야 지정 명령어 사용 가능
```

`flask run --host=0.0.0.0 --port=8080`

```python
return "<h1>OP.GG</h1>"
###
return send_file() # 해도 되지만 template를 사용하지 못함
# c9은 jinja라는 template 사용 => render_template 가져와야함
```

`app = Flask(__name__, template_folder="views")`

`words = request.args.get('words')`



```html
<form action="/search">
    <input type="text" name="words"/>
    <input type="submit" value="Submit"/>
</form>

form -> 어디론가 보내줌
```



---

---

---

# Bootstrap

* 반응형 웹을 만들기 위한 라이브러리 툴



getbootstrap.com

get started

css

copy

```html
<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.2.1/css/bootstrap.min.css" integrity="sha384-GJzZqFGwb1QTTN6wy59ffF1BuGJpLSa9DkKMp0DgiMDm4iYMj70gZWKYbI706tWS" crossorigin="anonymous">

<title></title> 바로 위에다가 붙여넣기
```

JS

```html
<link> 아래에다 붙여넣기

<script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.6/umd/popper.min.js" integrity="sha384-wHAiFfRlMFy6i5SRaxvfOCifBUQy1xHdJ/yoi7FRNXMRBu5WHdZYu1hA6ZOblgut" crossorigin="anonymous"></script>
<script src="https://stackpath.bootstrapcdn.com/bootstrap/4.2.1/js/bootstrap.min.js" integrity="sha384-B0UglyR+jN6CkvvICOB2joaf5I4l3gm9GU6Hc1og6Ls7i6U/mkkaduKaBhlAXv9k" crossorigin="anonymous"></script>
```

왼쪽 메뉴에서 Component

* webservice에서 쓸 수 있는 code의 조각들 모음
* 이 블록들을 복붙해서 쓰는 경우가 앞으로 많을 것



> Jumbotron - 위에 전광판같은 거

Fluid jumbotron

copy

```html
<div class="jumbotron jumbotron-fluid">
  <div class="container">
    <h1 class="display-4">Fluid jumbotron</h1>
    <p class="lead">This is a modified jumbotron that occupies the entire horizontal space of its parent.</p>
  </div>
</div>

<h1> 위에다가
</h1>
```



> form

첫번째꺼 copy

```html
div와 form 사이에

<form>
  <div class="form-group">
    <label for="exampleInputEmail1">Email address</label>
    <input type="email" class="form-control" id="exampleInputEmail1" aria-describedby="emailHelp" placeholder="Enter email">
    <small id="emailHelp" class="form-text text-muted">We'll never share your email with anyone else.</small>
  </div>
  <div class="form-group">
    <label for="exampleInputPassword1">Password</label>
    <input type="password" class="form-control" id="exampleInputPassword1" placeholder="Password">
  </div>
  <div class="form-group form-check">
    <input type="checkbox" class="form-check-input" id="exampleCheck1">
    <label class="form-check-label" for="exampleCheck1">Check me out</label>
  </div>
  <button type="submit" class="btn btn-primary">Submit</button>
</form>
```





---

---

---

---

---

