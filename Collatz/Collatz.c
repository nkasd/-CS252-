/* Assignment 3.21
The Collatz conjecture, for any given number,
     n = n/2   (even)
       = 3*n+1 (odd); till n==1
Use fork(), wait(), error check for n>=0  */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>    //provides access to the POSIX operating system API
#include<sys/types.h> //defines data types used in system source code
#include<sys/wait.h> //Keep the process whose status is returned in infop in a waitable state


void Collatz(int num)
{
  pid_t PID;
  PID = fork();

  if(PID<0)   //If error while Forking
  printf("ERROR(Unable to create child process)");

  else if(PID==0)   //proceeds with calculating next number in the series
  {
    printf("Child Process Initiated\n %d\n", num);
    
    //Recalculating Num
    if(num==1)
   { printf("Collatz ConjectureSequence completed");return;}

    if (num&1) //odd
    num=3*num+1;
    else       //even
    num=num/2;
  }
  //recall Collatz in order to find the next element
  Collatz(num);

  else
  {
    printf("Awaiting Child Process\n");
    wait(NULL);
    printf("Parent Process Completed for %d\n", num);
    exit(1);
    return;
  }
}





int main()
{ int n;
  printf("Enter the number:");
  scanf("%d",&n);
  /*if(n<=1)  // IF there is an input
  {printf("Enter n:\n");return 0;}*/

  if(n<=0)  // If Input >0
  {printf("Invalid Input\n");return 0;}

    Collatz(n);   //RUN Collatz
  return 0;
}

