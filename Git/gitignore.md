`touch .gitignore`



```txt
*.txt
/__pycache__
```



Exclude those which already started version controlling:

`git -rm --cached *.txt`

`git -rm -r --cached /__pycache__` for repositories

