file=$1
if [ $# -eq 1 ]
then
dirx="."
else
dirx="$2"
fi
set -- `ls -l $file`
lcnt=$2
if [ $lcnt -eq 1 ]
then
echo "No other links"
exit 0
else
set -- `ls -i $file`
inode=$1
find "$dirx" -xdev -inum $inode -print
fi