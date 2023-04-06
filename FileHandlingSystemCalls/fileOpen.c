#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
   
   //int fd1 = open("files.txt",O_RDONLY); //for reading the data from file 
   int fd1 = open("files.txt",O_RDONLY|O_CREAT); // for writing the data into file , this will first create the file and then open it 
   
    if(fd1<0){
        perror("Failed to open :  ");
        exit(1);
    }
     printf("File opened with file descriptor = %d\n",fd1);
    if(close(fd1)<0){
        perror("Failed to close the file:  ");
        exit(1);
    }
    printf("Closed with file descriptor = %d\n",fd1);



return 0;
}
