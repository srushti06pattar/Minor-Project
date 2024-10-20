
file=$1
if [ -e $file ]
then
    creation_time=$(stat -c %y $file)
    echo "creation time of $file:$creation_time"
else
    echo "invalid file"
fi