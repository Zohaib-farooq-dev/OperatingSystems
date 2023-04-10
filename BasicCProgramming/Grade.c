#include <stdio.h>
#include <stdlib.h>

int main(){
   
   int marks;
   printf("Enter the marks \n");
   scanf("%d",&marks);
   
   if(marks>50){
       if(marks>90){
          printf("Grade is A \n");
        }else if(marks>85 && marks<90){
          printf("Grade is A-\n");
        }else if(marks>80 && marks<85){
          printf("Grade is B+\n");
        }else if(marks>75 && marks<80){
          printf("Grade is B\n");
        }else if(marks>70 && marks<75){
          printf("Grade is C\n");
        }else if(marks>65 && marks<70){
          printf("Grade is C-\n");
        }else if(marks>60 && marks<65){
          printf("Grade is D\n");
        }
   }else{
     printf("Students is Fail");
     }

return 0;
}
