#printing all odd numbers form 0-100 using while loop 
num=1
echo "Printing all the odd numbers between 0-100"
while [ $num -lt 100 ]
do 
  echo $num
  ((num++))
  ((num++))
  
done 
  
