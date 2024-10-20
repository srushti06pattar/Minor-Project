set `date`
if [ $3 -le 9]
then
    n=`cal | tail -n +3 | grep -n "$3" | cut -d ":" -f1 | head -n1`
    n=`expr $n + 2`
    cal|sed "$n s|$3|*|"
else
    cal|sed "s|$3|**|"
fi