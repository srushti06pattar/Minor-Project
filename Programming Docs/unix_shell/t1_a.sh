for i in $*
do
if [ -d $i ]
then
echo "large filename size is"
echo `ls -Rl $1 | grep "^-" | tr -s ' ' | cut -d' ' -f 5,8 | sort -n| tail -1`
else
echo "not directory"
fi
done