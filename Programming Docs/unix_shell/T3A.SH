echo "Enter a file name"
read file
if [ -f $file ]
then
set -- `ls -l $file`
echo "file permission: $1"
echo "Number of links:$2"
echo "User name:$3"
echo "Group name: $4"
echo "Filesize : $5 bytes"
echo "Date of modification:$6"
echo "time of modification:$7"
echo "Name of file:$8"
else
echo "file does not exist"
fi
#Check the permissions
echo "enter the file name1"
read f1
ls -l $f1