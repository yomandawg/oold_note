# M:N

> M V T : M이 가장 많은 일을 하고, V는 중간자 역할만 하는게 좋음 : model FFFFFAAAAATTTTT    

![IMG_0025](C:\Users\student\note\Django\IMG_0025.PNG)

- 1 : N

  - 1에서 N으로 간편하게 접근하자 : one.N_set

- M : N

  - 1:M 과 N:1 사이에 새로운 Table이 존재
  - django는 알아서 table을 해줌 (models.py에서 새로운 테이블 만들어 줄 필요가 없음)

  

```
mkdir SCHOOL
cd SCHOOL
pyenv virtualenv 3.6.7 school-venv
pyenv local insta-venv
pip install --upgrade pip
pip install Django==2.1.8
pip install django ipython django-extensions
django-admin startproject school .
```

```python
from django.db import models
from faker import Faker
import random

fake = Faker('ko_KR')

class Student(models.Model):
    name = models.CharField(max_length=30)
    student_id = models.IntegerField()
    
    # 객체 생성없이 사용 가능
    @classmethod
    # 더미 데이터를 자동으로 넣어주는 친구
    def dummy(cls, n):
        for _ in range(n):
            cls.objects.create(name=fake.name(), student_id=random.randint(2000, 2020))

    
    
    # 객체 생성 후에, 객체가 사용하는 형식
    def __str__(self):
        return self.name
    
class Lecture(models.Model):
    title = models.CharField(max_length=100)
    
    # def __str__(self):
    #     return self.title
    
class Enrollment(models.Model):
    lecture = models.ForeignKey(Lecture, on_delete=models.CASCADE)
    student = models.ForeignKey(Student, on_delete=models.CASCADE)
    
    
    def __str__(self):
        # self > Enrollment 객체
        # self.student_set
        return f"{self.student.name} 님이 {self.lecture.title} 과목을 수강하였습니다."
```

- join table에 중복 방지 처리가 되어 있지 않음!



### Django ORM이 지원하는 M : N (ManyToManyField)

- 매우 간편하고 중복 방지 처리가 되어있음

- meta data : 데이터(data) 에 대한 데이터(meta data)

  > django model meta options

```python
# 이번엔 Django가 지원하는 M:N 구조로 진행
class Client(models.Model):
    name = models.CharField(max_length=30)
    
    # class Meta:
    #     ordering = ['name', ]
    @classmethod
    def dummy(cls, n):
        for _ in range(n):
            cls.objects.create(name=fake.name())
        
class Resort(models.Model):
    name = models.CharField(max_length=30)
    # models.ManyToManyField(모델 클래스 이름, 온딜릿도 필수 아님)
    clients = models.ManyToManyField(Client)
    # 포함관계는 이해하기 쉬운 쪽에(Client or Resort 상관없음) 쓰자, 단! 순서(선언) 중요 (문법)
    
    @classmethod
    def dummy(cls, n):
        for _ in range(n):
            cls.objects.create(name=fake.company())
```

- sql문을 구경해보자

```
python manage.py makemigrations
python manage.py migrate
python manage.py sqlmigrate sugangs 0002
```

- Shell에서 확인해보자

```python
python manage.py shell_plus
###

Resort.dummy(5)
Client.dummy(20) 
resort.clients
resort.clients.all()
resort.clients.add(man)
resort.clients.all()
resort.clients.remove(Client.objects.last())

# 매우 간편 + 중복 방지도 되어있음!
```