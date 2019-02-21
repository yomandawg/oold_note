# Django Advanced

> `python manage.py runserver $IP:$PORT`

---

## 데이터베이스 관계

* **1:1 관계**

  * 동등관계
  * 쌍방향 조회 가능

  | id   | name   | 주민번호 |
  | ---- | ------ | -------- |
  | 1    | 김지수 | 9xxxxx   |
  | 2    | 김지수 | 8xxxxx   |

  * 주민번호 -> id, id -> 주민번호
  * 남편 -> 부인, 부인 -> 남편

* **1:N 관계**

  * 1 to many, has many, belongs to
  * 하나가 여러개에 mapping됨

  | 학급 | 학생   |
  | ---- | ------ |
  | 1    | 홍길동 |
  | 1    | 박길동 |
  | 2    | 홍길동 |

  * 학급1 -> [홍길동, 박길동], 학급2 -> [홍길동]
  * 홍길동 -> 학급1 or 학급2?

* **M:N 관계** 

  * many to many
  * 여러 관계가 다중으로 엮여있음

  | 수업     | 학생_id |
  | -------- | ------- |
  | 회계원리 | id_1    |
  | 회계원리 | id_2    |
  | 채플     | id_1    |
  | 채플     | id_2    |
  | 공학수학 | id_1    |

  * 회계원리 -> [id_1, id_2], id_1 -> [회계원리, 채플, 공학수학]

* *관계없음*

  * 관계가 없는 데이터들

---

## 댓글 기능

* 구조

```html
articles/templates/articles/detail.html
<ul>
    <li>댓글1</li>
    <li>댓글2</li>
    ...
</ul>
```

#### 댓글 데이터베이스

- `articles` table

  | id   | title | content | comments                         |
  | ---- | ----- | ------- | -------------------------------- |
  | 1    | Title | Content | [comment, comment, comment, ...] |

- `comment` table

  | 1       | 2       | 3       | ...  |
  | ------- | ------- | ------- | ---- |
  | comment | comment | comment | ...  |

* 두가지 테이블을 연결해줘야함

* 누가 누구의 정보를 가지는지 효율적으로 설계

  * 1:N의 관계 - *foreign_key : N*

  | id   | content                 | article_id (foreign key) |
  | ---- | ----------------------- | ------------------------ |
  | 1    | 첫번째 글의 첫번째 댓글 | 1                        |
  | 2    | 두번째 글의 첫번째 댓글 | 2                        |
  | 3    | 첫번째 글의 두번째 댓글 | 1                        |

```python
# articles/models.py
class Comment(models.Model):
    content = models.TextField()
    # 속한 글의 ForeignKey, 속한 글이 지워졌을 경우 모든 comment 삭제
    article = models.ForeignKey(Article, on_delete=models.CASCADE)
```

* `on_delete=models.CASCADE`: 글이 지워지면 `models`에 속한 댓글도 다 지움
  * db에 남겨두지 말고 지워

* `models.py` 변경, need to migrate

```bash
# sitback:~/workspace/BOARD $
python manage.py makemigrations
>     - Create model Comment # Comment model 추가
python manage.py migrate
python manage.py sqlmigrate articles 0004 # migrate 내역 확인
```

```bash
python manage.py dbshell
sqlite> .tables
sqlite> .schema articles_comment
```

#### ORM try

```python
python manage.py shell_plus
# from articles.models import Article, Comment 가져온 것 확인
Article.objects.all()
> ...
article = Article.objects.first()
article.id
> 12
comment = Comment(content="12  댓글1", article=article) # 객체 그대로 넣어줘도 됨
comment.content
> '12 댓글1'
comment.article
> <12, trhkghadf : fhkhgadf>
comment.save()
Comment.objects.first().content
> '12 댓글1'
Comment.objects.first().article # 속한 article 조회 가능
# Article.objects.get(Comment.objects.first().article_id) 를 Django가 간편화해줌
> <12, trhkghadf : fhkhgadf>
Comment.objects.first().article_id 객체의 인자도 확인 가능
> 12
Comment.objects.filter(article_id=12).all()
> # All comments in article_id=12
Article.objects.first().comment_set.all()
> # Django ORM version
```

* Django ORM은 DB관계를 효율적으로 유추해서 간편화해주는 코드 구현 가능
  * `Comment.objects.first().article`
  * `Article.objects.first().comment_set.all()`

#### 댓글 기능 구현

```python
# articles/urls.py
urlpatterns = [
    ...
    path('<int:article_id>/comment/', views.comment, name="comment"),
]
```

```python
# article/views.py
from .models import Article, Comment

def detail(request, article_id):
    article = Article.objects.get(id=article_id)
    comments = Comment.objects.filter(article_id=article_id).all()
    context = {
        'article': article,
        'comments': comments,
    }
    return render(request, 'articles/detail.html', context)

def comment(request, article_id):
    # 댓글을 작성한다
    content = request.POST.get('content')
    comment = Comment(content=content, article_id=article_id)
    # <article=객체>로도 가능
    comment.save()
    return redirect('detail', article_id)
```

```html
# detail.html
<h3>댓글</h3>
<form action="{% url 'comment' article.id %}" method="POST">
    <input type="text" name="content"/>
    <input type="submit" value="Submit"/>
    {% csrf_token %}
</form>
<ul>
    {% for comment in comments %}
    <li>{{ comment.content }}</li>
    {% endfor %}
    
	{% for comment in article.comment_set.all %}
    <li>{{ comment.content }}</li>
    {% endfor %}
</ul>
```

* `related_name="comments"`: call `Comment` table directly

```python
# models.py
class Comment(models.Model):
    content = models.TextField()
    article = models.ForeignKey(Article, on_delete=models.CASCADE, related_name="comments")
```

```html
<ul>
    {% for comment in article.comments.all %}
    <li>{{ comment.content }}</li>
    {% endfor %}
</ul>
```







