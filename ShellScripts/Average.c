#include <stdio.h>
#include <stdlib.h>

int main(int argc , char** argv){

  //converting string arguments from CLI to int to easily find their average 
  int n1 = atoi(argv[1]);
  int n2 = atoi(argv[2]);
  
  
  //printing average of the srguments from CLI on the console
  printf("THe average of the integers : %.3f\n",((float)(n1+n2)/2));


  return 0;
}
