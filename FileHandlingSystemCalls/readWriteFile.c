#include<stdio.h>
#include <fcntl.h>
#include<string.h>
#include<stdlib.h>
#include <unistd.h>
int main()
{
int fd[2], sz; //creating array of file descriptor 
char *data = (char *) malloc(100*sizeof(char)); // allocating dynamic memory of char type
fd[0] = open("file_read.txt", O_RDONLY);//open file system call
if (fd[0] < 0) { perror("Failed to Open File for Reading: "); exit(1); }
sz= read(fd[0], data, 50);
printf("Data read = %s\n", data);
data[sz] = '\0'; //our array size is 100 and this will tell that at sz our data ends
fd[1] = open("file_write.txt", O_RDWR);//opening file for writing 
if (fd[1] < 0) { perror("Failed to Open File for Writing: "); exit(1); }
int wz = write(fd[1], data, strlen(data));
printf("sz = %d\n", wz);
printf("Data written = %s\n", data);
//closing files 
close(fd[0]);
close(fd[1]);

return 0;
};
