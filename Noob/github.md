sitback:~ $ ls
lib/  workspace/
sitback:~ $ cd workspace/
sitback:~/workspace $ ls
TrashApp/  __pycache__/  fakesearch/  vonvon/
sitback:~/workspace $ cd vonvon/
sitback:~/workspace/vonvon $ ls
__pycache__/  app.py  fish.csv  templates/
sitback:~/workspace/vonvon $ git init
Initialized empty Git repository in /home/ubuntu/workspace/vonvon/.git/
sitback:~/workspace/vonvon (master) $ git status
On branch master

No commits yet

Untracked files:
  (use "git add <file>..." to include in what will be committed)

        app.py
        fish.csv
        templates/

nothing added to commit but untracked files present (use "git add" to track)
sitback:~/workspace/vonvon (master) $ git add .
sitback:~/workspace/vonvon (master) $ git commit -m "first commit"
[master (root-commit) d530d2e] first commit
 7 files changed, 175 insertions(+)
 create mode 100644 app.py
 create mode 100644 fish.csv
 create mode 100644 templates/admin.html
 create mode 100644 templates/index.html
 create mode 100644 templates/junsaeng.html
 create mode 100644 templates/match.html
 create mode 100644 templates/pastlife.html
sitback:~/workspace/vonvon (master) $ git remote add origin https://github.com/yomandawg/flask_project.git
sitback:~/workspace/vonvon (master) $ git push -u origin master
Username for 'https://github.com': yomandawg
Password for 'https://yomandawg@github.com': 
sitback:~/workspace/vonvon (master) $ git push -u origin master
Username for 'https://github.com': yomandawgshit@gmail.com
Password for 'https://yomandawgshit@gmail.com@github.com': 
sitback:~/workspace/vonvon (master) $ git push -u origin master
Username for 'https://github.com': yomandawg
Password for 'https://yomandawg@github.com': 
sitback:~/workspace/vonvon (master) $ git push -u origin master
^[[AUsername for 'httpyomandawg@github.com': awg
sitback:~/workspace/vonvon (master) $ git push -u origin master
Username for 'https://github.com': yomandawg
Password for 'https://yomandawg@github.com': 
Counting objects: 10, done.
Delta compression using up to 8 threads.
Compressing objects: 100% (9/9), done.
Writing objects: 100% (10/10), 2.42 KiB | 2.42 MiB/s, done.
Total 10 (delta 4), reused 0 (delta 0)
remote: Resolving deltas: 100% (4/4), done.
To https://github.com/yomandawg/flask_project.git
 * [new branch]      master -> master
  Branch master set up to track remote branch master from origin.
  sitback:~/workspace/vonvon (master) $ 