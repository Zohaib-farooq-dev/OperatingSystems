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
   char str[10] = {0};
   int nic ;
  
   do{
     printf("Enter your details as following sequence : 1)Name, 2)Father Name ,3) NIC , 4) City");
     scanf("%s",name);
     scanf("%s",fatherName);
     scanf("%d",&nic);
     scanf("%s",cityName);
     
     int r = rand()%100;
    sprintf(str,"%d",r);
    strncat(str,".txt",4);
     
     printf("\n %s",str);
     int fd1 = open(str,O_RDWR|O_CREAT|O_APPEND);
     if(fd1<0){
        perror("Failed to open file for writing : ");
        exit(1);
      }
      write(fd1,("%s\n",name),strlen(name));
      
      write(fd1,("%s\n",fatherName),strlen(fatherName));
      write(fd1,("%d\n",&nic),sizeof(nic));
      write(fd1,("%s\n",cityName),strlen(cityName));
      
      
      close(fd1);
      
      int fd = open(str,O_RDONLY);
      read(fd1,name,strlen(name));
      read(fd1,fatherName,strlen(fatherName));
      read(fd1,&nic,sizeof(nic));
      read(fd1,cityName,strlen(cityName));
      
      printf("\n%s\n%s\n%d\n%s",name,fatherName,nic,cityName);
      
 
   
   }while(cont=='y');
   


return 0;
}
