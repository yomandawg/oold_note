

# ORM

* Object-relational mapping
* Relational database의 record를 객체로 1:1 대응시킴

---

* **tuple** `	fetchall()`

  ```python
  [
  	(1, "제목입니다.", "내용입니다.", "강동주", "2019-02-07")
      (2, "제목2.", "내용2", "손지명", "2019-02-07")
  ]
  ```
  *  제목: `articles[0][1]`

* **dictionary**

  ```python
  [
      {'id': 1, 'title': '제목3', 'content': '내용3', 'author': '신동찬'}
  ]
  ```

  * 제목: `articles[0]['title']`

* object

  * *원하는 형태로 자료를 조작할 수 있다.* - **매우 큰 장점**

  ```python
  class Article:
      def __Init__(self, id, title, content, author, created_at):
          self.id = id
          self.title = title
          self.content = content
          self.author = author
          self.created_at = created_at
      
      # 객체 지우기
      def delete(self):
          del(self)
          
  a1 = Article(1, '제목', '내용', '강동주', '2019-02-07')
  a2 = Article(2, '제목2', '내용2', '손지명', '2019-02-07')
  
  articles3 = [
      a1, a2
  ]
  ```

  * 제목: `articles3[0].title`
  * 지우기: `a2.delete()`

---

## SQLAlchemy

* python SQL tool for object-relation
* 관계형 db를 객체화시켜서 만들어주는 tool
  * Dropbox, Yelp!, reddit

* `sudo pip3 install sqlalchemy`

* `sudo pip3 install flask_sqlalchemy`

  ```python
  from flask import Flask
  from flask_sqlalchemy import SQLAlchemy
  app = Flask(__name__)
  app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:////tmp/test.db'
  app.config["SQLALCHEMY_TRACK_MODIFICATIONS"] = False # 안 꺼주면 Error
  db = SQLAlchemy(app) # Flask app과 SQLAlchemy 합체
  db.init_app(app)
  
  class Ariticle(db.Model): # db.Model 상속
      # CREATE TABLE articles ( ... )
      __tablename__ = "articles"
      # 상속받은 db.Model의 Column()
      # id INTEGER PRIMARY KEY AUTOINCREMENT
      id = db.Column(db.Integer, primary_key=True, )
      # title TEXT NOT NULL
      title = db.Column(db.String, nullable=False)
      content = db.Column(db.String, nullabe=False)
      author = db.Column(db.String, nullable=False)
      created_at = db.Column(db.String, nullable=False)
      
  # 정의한 정보를 바탕으로 db 만들어짐
  db.create_all()
  
  @app.route('/')
  def index():
      # SELECT * FROM articles
      articles = Aricle.query.all()
      # ORM 객체처럼 다룰 수 있게 해준다 {{ articles[0].title }}
      return render_template('index.html', articles=articles)
      
  @app.route('/create')
  def create():
      title = request.args.get('title')
      content = request.args.get('content')
      # ORM을 사용하여 데이터를 저장한다.
      a = Article(title=title, content=content)
      # session @ cursor
      db.session.add(a)
      db.session.commit()
      
      return redirect('/')
  ```

  * Flask X SQLAlchemy

  

  ---

  `flask run --host=0.0.0.0 --port=8080`

  

