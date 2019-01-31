# Database

* C9 Blank template project

`sudo pip3 install flask`

`django-admin startproject`


### 익명 질문앱
* `https://asked.kr/yomandawg`

* `flask run --host=0.0.0.0 --port=8080`



```python
quest = request.args.get('quest')
with open('csv/quest.txt') as f:
    f.write(quest + '\n')
```

* `readlines()` 파일의 모든 라인을 읽어서 각각의 줄을 요소로 갖는 리스트로 리턴한다.

```python
with open('csv/quest.txt', 'r') as f:
	quests = f.readlines()
```

* ` render_template()` **Jinja**로 render

```html
{% for q in quests %}
	<p>{{ q }}</p>
{% endfor %}
```

> `txt` 
>
> `csv` 
>
> `json` : dictionary 형태





# SQL

* structured queried language
* 코드로 데이터베이스를 조작하는 특수 목적 언어

### RDBMS

>* 관계형 모델 기반 데이터베이스 관리 시스템
>*  오픈소스 RDBMS
>  * MySQL
>    - ORACLE이 사감... &rarr; AURORA 창업
>  * SQLite
>    - 가벼워서 안드로이드 기본 채택
>    - 임베디드 소프트웨어(적은 용량)
>  * PostgreSQL
>    - MySQL ORACLE화로 부상
>* ORACLE
>  - 데이트베이스 대기업
>  - Enterprise 용
>  - 한국은 ORACLE 거의 독점
>    - ORACLE에서 탈피하자: 카카오뱅크 MySQL(은행은 초거대 DB 필요)
>* MS SQL



### Schema

* datatype 정의

  * type 외에는 strictly block

    

* | column | datatype |
  | :----: | :------: |
  |   id   |   INT    |
  |  age   |   INT    |
  |  name  |   text   |
  | phone  |   text   |
  | email  |   text   |

* 한 데이터베이스 안에 여러 테이블이 들어갈 수 있다

* 전체 파일이 데이터베이스

* 열(column) / 행(row)로 구분

* Primary Key (**PK**)

  * 고유 **id값**



### CRUD

> *create, read, update, delete*



---

---



# SQLite

**Initiation** 

* `$sqlite3`

**명령어 `.`로 시작**

- CSV mode: `.mode csv`

- import csv file as *name*: `.import hellodb.csv hellodb`
- view current tables: `.tables`
- column view: `.mode column`
- show headers: `.headers on`

**Viewing table**

- `SELECT * FROM hellodb;`
- `SELECT first_name FROM hellodb;`
- `SELECT last_name, first_name, age FROM hellodb;`





### SQL practice



* *sqlite* file creation: `sqlite3 tutorial.sqlite3`

* view *sqlite* databases: `.databases`

* create table: `CREATE TABLE classmates ( ... )`

```sqlite
CREATE TABLE classmates (
	id INTEGER PRIMARY KEY, 
	name TEXT
);
```

* view tables: `.tables`

* view schema: `.schema <table>` 

* table deletion: `DROP TABLE <table>;`

* read sql(get sql files): `.read create_table.sql`



* Inserting values:  `INSERT INTO classmates (name, age) VALUES ('홍길동', 23);`
* if no values specified: `INSERT INTO classmates VALUES (3, '홍길동', 30, '서울');`
  * need to specify all values
  * auto-incrementation of id's
* view all rows in a table: `SELECT * FROM classmates;`

* Delete table: `DROP TABLE classmates;`
* view schemas: `.schema classmates`

```sql
CREATE TABLE classmates (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL,
    age INTEGER NOT NULL,
    address TEXT NOT NULL
);
```

* `NOT NULL` needs to be filled



* can select certain values `SELECT id, name, age FROM classmates;`

* `OFFSET` marks the start value, `LIMIT` limits the total output
  * `SELECT id, name, age FROM classmates LIMIT 2 OFFSET 1;`



* get certain value from table

```sql
SELECT *
FROM classmates
WHERE name = '강동주'
```

* can also use `=` `==` `is`

* searching by `id` is the convention: `SELECT * FROM classmates WHERE id == 3;`

* `SELECT id, name, address FROM classmates WHERE address = '서울'`

* deletion: `DELETE FROM classmates WHERE id = 3;`
  * `DELETE FROM classmates WHERE id IS NULL;`

* update: `UPDATE classmates SET address = '부산' WHERE id = 3;`



* csv file mode: `.mode csv

* import other files`.import users.csv users`

* output by limit `SELECT * FROM users LIMIT 10;`

* show how many rows are in the table`SELECT COUNT(*) FROM users;`

* `DROP TABLE users;`

* `.schema users`

  

* `SELECT COUNT(*) FROM users WHERE age > 30;`

* `SELECT last_name, first_name, MAX(balance) FROM users;`



* `SELECT * FROM users WHERE first_name LIKE "선%";`
* `SELECT * FROM users ORDER BY age ASC LIMIT 10;`
* `SELECT * FROM users ORDER BY age DESC LIMIT 10;`

* `SELECT * FROM users ORDER BY age, last_name ASC LIMIT 10;`



* CSV는 text로 출력되는데, ORDER로 검색할 때 숫자가 9면 그냥 출력함
  * text를 integer로 바꿔야해



### 여기까지 한 것

1. sqlite3에 접속
2. table 관련 SQL 작성(CREATE TABLE)
3. CRUD(Create, Read, Update, Delete) SQL



----

---



## Python and SQL

> `import sqlite3`



* database cursor 
  * 일련의 데이터에 순차적으로 액세스할 때 검색 및 '현재 위치'를 포함하는 데이터 요소



```python
import sqlite3

# 1. sqlite3에 접속 // > sqlite3 test.sqlite3
conn = sqlite3.connect('test.sqlite3') # 연결을 마치고 난 객체를 conn에 저장

# a. cursor 생성 => cursor()
# b. sql문 작성 => execute()
# c. cursor 실행 => fetchone() | fetchall()
cur = conn.cursor()
cur.execute('SELECT * FROM users users LIMIT 10') # string 단위로 넣어주기 때문에 delimter ';' 필요 없음
data = cur.fetchall()

# 2. SQL 작성 후 실행
# - table 관련 SQL 작성(CREATE TABLE)
# - CRUD(Create, Read, Update, Delete) SQL
```



* `database.commit()`
  * 커밋 없이는 세션에 임시 정보 저장된 상태로 실제 db에 반영되지 않음
  * *Read*는 db를 건드리지 않기 때문에 commit 안해도 된다.