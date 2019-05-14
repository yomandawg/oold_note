# IaaS

> Infrastructure as a Service
>
> AWS, GCP, Azure
>
> EC2, EB
>
> 서비스 운용할 때 클라우드 플랫폼에서 활용하게 만들어주는 툴



* Python Anywhere
* Digital Ocean
* Heroku





## Heroku

* 서버 자동화
* `pip install django-heroku`
  * `psycopg2 `- PostgreSQL

```python
# instagram/settings.py
import django-heroku
...
STATIC_ROOT = os.path.join(BASE_DIR, 'staticfiles') # static 파일 관리

django_heroku.settings(locals()) # 현재 환경을 load하겠다
```



* WSGI - 문지기의 문지기
  * web-server gateway interface
  * 네트워크 HTTP 패킷 요청을 해석해주는 중간자
  * `pip install gunicorn`
    * django(python)이 알아들을 수 있게 알려줌



* Heroku 내의 환경설정

```json
// INSTAGRAM/runtime.txt

python-3.6.7 // python-3.6.7 깔아줘
```

* FTP(File Transfer Protocol)



* `pip freeze` - 깔린 package list with version
* `pip freeze > requirements.txt`
  * 명령어가 txt파일로 들어감



* `Procfile` &rarr; for `gunicorn`

```json
// INSTAGRAM/procfile

web: gunicorn instagram.wsgi // projectname.wsgi
```

* `instagram/wsgi.py`


* `heroku --version` - C9 이미 깔려있음
* `heroku login`
* `heroku create <global name>`

  * `heroku create` - randomly create name
* `git remote -v`
  * `heroku  https://git.heroku.com/fierce-anchorage-48734.git (fetch)`
  * `heroku  https://git.heroku.com/fierce-anchorage-48734.git (push)`
* `git push heroku master`
*  자동으로 세팅 적용 및 push 관리

&rarr; **`https://fierce-anchorage-48734.herokuapp.com/`**

* `heroku run python manage.py migrate`

  * `heroku run` - run commands

* `heroku run python manage.py createsuperuser`

  

* connect domain

  * `heroku domains:add <domain>`





# Javascript + Django

```html
<!-- Vue.js로 동작하는 팔로워 -->
  <div id="app">
    <button v-show="loading" @click="follow({{ people.id }})" :class="{'btn': true, 'btn-primary': !followed, 'btn-dark': followed}">Vue Follow</button>
    <p>[[ test ]]</p>
    <p>팔로우 여부: [[ followed ]]</p>
  </div>

<script>
  const app = new Vue({
    // Django와 <mustache> 겹치므로 출력형태 변경
    delimiters: ['[[', ']]'],
    el: '#app',
    data: {
      test: 'success',
      followed: '',
      loading: false,
    },
    methods: {
      follow: function(person_id) {
        axios.get(`/accounts/${person_id}/vuefollow/`)
          .then(res => res.data)
          .then(data => {
            this.followed = data.followed
          })
      },
      checkFollow: function(person_id) {
        axios.get(`/accounts/${person_id}/checkfollow/`)
          .then(res => res.data)
          .then(data => {
            this.followed = data.followed
            this.loading = true
          })
      },
    },
    // vue 객체 생성 전에 하는 것
    beforeMount: function() {
      this.checkFollow({{ people.id }})
    }
  })
</script>
```

```python
# views.py
from django.http import JsonResponse

def vue_follow(request, user_id):
    person = get_object_or_404(get_user_model(), pk=user_id)
    if request.user in person.follows.all():
        person.follows.remove(request.user)
        followed = False
    else:
        person.follows.add(request.user)
        followed = True
    return JsonResponse({'followed': followed})
    
def check_follow(request, user_id):
    person = get_object_or_404(get_user_model(), pk=user_id)
    if request.user in person.follows.all():
        followed = True
    else:
        followed = False
    return JsonResponse({'followed': followed})
```

