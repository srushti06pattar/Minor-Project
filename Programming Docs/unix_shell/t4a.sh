y=$#
if [ $y -le 0 ]
then
echo "argument is not entered"
else
for file in $*
do
echo "$file"
n=`echo -n "$file" | tr "[a-z]" "[A-Z]"`
mv "$file" "$n"
echo "$n"
done
fi