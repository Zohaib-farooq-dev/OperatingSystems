#takin the name of file form user
read -p "Enter the name of File  in the form 'name.txt'  : " name
#creating the .txt file
touch $name 
#compiling and running the C file
gcc FileScript.c -o filescript  && ./filescript  $name 

