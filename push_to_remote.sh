#!bin/sh

CUR_BRANCH=$(git branch | grep "*" | sed 's/* '// )

git add .
git commit -m "$CUR_BRANCH: $*"
git push origin $CUR_BRANCH
