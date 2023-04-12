#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>


int main(){
   
   char cont ='n';
   char* name = (char*)malloc(100*sizeof(char));
   char* fatherName = (char*)malloc(100*sizeof(char));
   char* cityName = (char*)malloc(100*sizeof(char));
   char str[10] = {0};
   char* nic = (char*)malloc(20*sizeof(char));
   char newline = '\n';
   int id=0;
  
   do{
     printf("Enter the details of user \n\n");
     printf("Enter your details as following sequence : 1)Name, 2)Father Name ,3) NIC , 4) City");
     scanf("%s",name);
     scanf("%s",fatherName);
     scanf("%s",nic);
     scanf("%s",cityName);
     
     srand(time(0));
     int r = rand()%100;
    sprintf(str,"%d",r);
    strncat(str,".txt",4);
     
     printf("\n %s",str);
     int fd1 = open(str,O_CREAT|O_APPEND|O_RDWR|O_NONBLOCK,0666);
     if(fd1<0){
        perror("Failed to open file for writing : ");
        exit(1);
      }
      write(fd1,"Name : ",7);
      write(fd1,name,strlen(name));
      write(fd1,&newline,1);
      write(fd1,"Father Name : ",14);
      write(fd1,fatherName,strlen(fatherName));
      write(fd1,&newline,1);
      write(fd1,"CNIC : ",7);
      write(fd1,nic,strlen(nic));
      write(fd1,&newline,1);
      write(fd1,"City : ",7);
      write(fd1,cityName,strlen(cityName));
      write(fd1,&newline,1);
      
      
      close(fd1);
      
     
     printf("Do you want to add more users or not \n Enter 'y' to continue or 'n' to exit \n" );
     scanf("  %c",&cont); 
 
   
   }while(cont == 'y');
   
   
   
   


return 0;
}
