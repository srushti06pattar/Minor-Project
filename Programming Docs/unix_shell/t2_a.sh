if [ $# -eq 0 ] #Line1
then
echo "arguments not entered sorry try again "
else
ls -l $1 > f1 #Line5
x=`cut -c2-10 f1` #Line6
echo $x
ls -l $2 > f2
y=`cut -c2-10 f2`
echo $y
echo " "
if [ $x = $y ]
then
echo "permission of both files are same"
echo $x
else
echo "permission are different"
echo $x
echo $y
fi
fi