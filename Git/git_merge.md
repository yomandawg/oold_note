병합할 프로젝트(ex. project1) root에서 작업
( 병합되는 프로젝트의 root 폴더를 따로 만들면 예쁘게 병합됨 )

git remote add project2 ../project2
git fetch project2
git merge --allow-unrelated-histories project2/master # 또는 브렌치 이름
git remote remove project2
git commit -m 'Merge project2 into project1'  # 안해도 되는거 같음
git push --set-upstream origin master

mini_pjt_blog

