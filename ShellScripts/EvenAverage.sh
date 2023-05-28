#calculating the average of first 10 even numbers using for loop 
num=0
for ((i=1; i<20; i++))
do
  ((i++))
  num=$((num+i))
done
num=$((num/10))
#printing the average of fisrt ten even numbers
echo $num

