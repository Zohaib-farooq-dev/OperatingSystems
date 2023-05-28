#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/wait.h>

int main(){
                                           ///Part A//////
   // ALL Variables of the whole program 
   char* name = (char*)malloc(30*sizeof(char));
   char* department = (char*)malloc(30*sizeof(char));
   char performance ;
   int experience ;
   //variable fro storing random id of employees
   char* employeeId = (char*)malloc(20*sizeof(char));
   //variable to run loop
   char cont ='n';
   char newline = '\n';
   //2 variables for creating filename after getting employee id in hild process
   int id;
   char* Id = (char*)malloc(20*sizeof(char));
   //variable to store the increment 
   int increment;
   
   do{
      
      //taking input from the user
      printf("Enter the details of Employees \n\n");
      printf("Enter the Employee Name : ");
      scanf("%s",name);
      printf("Enter the Employee Department : ");
      scanf("%s",department);
      printf("Enter the Employee Experience (should be integer) : ");
      scanf("%d",&experience);
      printf("Enter the Employee Performance (should be B,A,W) : ");
      scanf("%s",&performance);
      
      //creating random number using rand function and srand function is used to generate a different number every time
      srand(time(0));
      int r = rand()%100;
      
      sprintf(employeeId,"%d",r);//converting the random int number into string
      strncat(employeeId,".txt",4);//concating ,txt eith random name to get proper filename 
      
      int fd = open(employeeId,O_CREAT|O_APPEND|O_RDWR,0666);//Opening file using open system call()
      if(fd<0){
         perror("Failed to open file : \n");
         exit(1);
       }
       
       //writing the all above data to file
      write(fd,name,strlen(name));
      write(fd,department,strlen(department));
      write(fd,&performance,1);
      write(fd,&experience,sizeof(experience));
      
      //closing the file
      close(fd);
      
      //asking the user whether he wants to continue or not 
      printf("Do you want to add more users or not \n Enter 'y' to continue or 'n' to exit \n" );
      scanf("  %c",&cont); 

   
   }while(cont == 'y');
   
   
   
   
                                                     ///Part B ///////
   pid_t pid = fork();
   
   if(pid<0){
      fprintf(stderr,"Fork Failed!!!");
   }else if(pid == 0){
   //taking employee id from the user
      printf("Enter the id of the Employee : ");
      scanf("%d",&id);
      //processing to make filename 
      sprintf(Id,"%d",id);
      strncat(Id,".txt",4);
      
      int fd1 = open(Id,O_RDONLY);
      if(fd1<0){
         perror("Failed to open file : \n");
         exit(1);
      }
      //reading the data from the file
        read(fd1,name,strlen(name));
        read(fd1,department,strlen(department));
        read(fd1,&performance,1);
        read(fd1,&experience,sizeof(experience));
        
        //comparing the performance so that we can calculate correct increment
        if(performance == 'B'){
           increment = experience * 10000;
        }else if(performance == 'A'){
           increment = experience * 5000;
        }else{
            increment = experience * 1000;
        }
        
        //printing the increement on console
        printf("Increment of Employee %s is %d\n: ",name,increment);
      
   }else{
   
      wait(NULL);
      printf("Child Process Completed!!"); 
   }

  return 0;
}
