#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>


int main(){
   
   char cont;
   char* name = (char*)malloc(100*sizeof(char));
   char* fatherName = (char*)malloc(100*sizeof(char));
   char* cityName = (char*)malloc(100*sizeof(char));
   long int nic ;
   
   do{
     printf("Enter your details as following sequence : 1)Name, 2)Father Name ,3) NIC , 4) City");
     scanf("%s",name);
     scanf("%s",fatherName);
     scanf("%ld",nic);
     scanf("%s",cityName);
     
     
     
   
   
   
   
   }while(cont=='y');
   


return 0;
}
