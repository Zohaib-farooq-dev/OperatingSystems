#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char** argv){

  //creating dynamic memory 
  char* name = (char*)malloc(30*sizeof(char));
  char* fname = (char*)malloc(30*sizeof(char));
  char* cnic = (char*)malloc(30*sizeof(char));
  char newline = '\n';
  
  //taking input from the user 
  printf("Enter the details : \n");
  printf(" Enter your Name    :     ");
  scanf("%s",name);
  printf(" Enter your Father Name    :     ");
  scanf("%s",fname);
  printf(" Enter your Cnic   :     ");
  scanf("%s",cnic);
  
  //opening the file from CLI arguments using OPEN system call 
  int fd = open(argv[1],O_RDWR,0666);
  if(fd<0){
     perror("failed to open the file ");
     exit(1);
  }
  
  //writing the user input into the fiel 
  write(fd,name,strlen(name));
  write(fd,&newline,1);
  write(fd,fname,strlen(fname));
  write(fd,&newline,1);
  write(fd,cnic,strlen(cnic));
  write(fd,&newline,1);
  
  //closing the file
  close(fd);
  


   return 0;
}
