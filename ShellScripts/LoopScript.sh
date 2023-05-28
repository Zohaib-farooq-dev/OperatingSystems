num=1
#-le means less than or equal to 
#-ge means  greater than or equal to 
#-lt means means lesser than 
# -gt means greater than 
#-ne means not equal to 
# -eq means equal to 
while [ ${num} -le 10 ]
do
  echo "Value of the counter =  $num"
  ((num++))
done

