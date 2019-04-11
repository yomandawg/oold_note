`touch .gitignore`



```txt
*.txt
/__pycache__
```



Exclude those which already started version controlling:

`git -rm --cached *.txt`

`git -rm -r --cached /__pycache__` for repositories





`git add posts/*` - 하위 경로의 모든 파일