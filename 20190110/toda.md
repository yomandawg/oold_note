* Tkinder
  * GUI program tool for python



* electron
  * desktop app tool



* spoqa
  * https://spoqa.github.io/2013/05/21/py2exe-and-py2app.html
  * 기술 블로그 보자! / 회사의 기술환경 알 수 있다
  * **py2exe** 로 윈도우프로그램 만듦



* AWS re:invent

* okky: 개발자 커뮤니티



1. 무한루프를 돌면서 사용자 입력을 기다림
2. 프로그램 끄면 bash에서도 꺼짐



# Tkinder

```python
from tkinter import * # import all

root = Tk()

root.mainloop() # program loop

"""
# 이거와 같다.
from flask import Flask

app = Flask()

app.run()
"""
```

1. 무한루프를 돌면서 사용자 입력을 기다림
2. 프로그램 끄면 bash에서도 꺼짐



* Graphical App or Game: 단순하게 무한루프 돌리고 tick계속 돌면서 화면을 새로운 정보로 계속 바꿔줌



* sys: command 칠 수 있는 import 있음



* https://076923.github.io/posts/Python-tkinter-1/



---

---

---



* **PEP8** : python styling guide

* 어느 회사든 style guide 있다 => 고유 linting system: 지켜야함
* **Lint** - 



---

---

---

## 알고리즘

* 개미 수열
  * 읽고 말하기 수열





------

----

```python
import a

print(dir(a)) 
```

```bash
$ python b.py
12
13
14
['__builtins__', '__cached__', '__doc__', '__file__', '__loader__', '__name__', '__package__', '__spec__', 'add_four', 'add_three', 'add_two']
```

* import: 기본적으로 a를 실행해보고 가져온다





```python
if __name__ == "__main__"
```

> python은 compile언어가 아니기때문에
>
> 실행한 파일이 시작점(예: python a.py : a.py가 시작점)이 `__main__` 
>
> ​	시작점 (`__name__ == '__main__'`들어가있어)
>
> * compile: 컴퓨터가 읽을 수 있는 상태로 먼저 다한다음에 main부터 쭉 실행해감(시작점: main)