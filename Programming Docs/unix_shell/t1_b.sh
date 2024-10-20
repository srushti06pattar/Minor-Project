echo "enter the pathname"
read p
i=1
j=1
len=`echo $p|wc -c`
while [ $i -le $len ]
do
x=`echo $p | cut -d / -f $j`
namelength=`echo $x|wc -c`
mkdir $x
cd $x
pwd
j=`expr $j + 1`
i=`expr $i + $namelength`
echo $g
done