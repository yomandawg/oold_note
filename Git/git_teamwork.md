# Teamwork using Github

> 1. 소통(팀원과 소통 & github 소통)
> 2. 팀장 주도



```bash
git init
git add .
git commit -m 'first_commit'
```



## branch 관리

1. master 은 동의 없이 건들지 않는다.

```bash
(작업 후)
...
(원칙: 작업 시작 전 항상 origin/master을 확인하라 - 기준은 origin/master)
git checkout master
git pull origin master
git branch -d john (작업 시작 전 항상 브랜치는 깔끔하게 지워준다)
git checkout -b john
(작업 후)
git add .
git commit -m 'navbar 추가'
git push origin john
(github pull request - automatic merge, 코드리뷰 권한설정)
(branch 지우고싶으면 overview에서 가능)
```

