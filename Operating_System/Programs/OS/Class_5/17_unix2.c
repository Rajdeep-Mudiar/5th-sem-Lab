// 17)PROGRAM FOR SYSTEM CALLS OF UNIX OPERATING SYSTEM(fork, getpid, exit) 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int pid, pid1, pid2;
    pid = fork();
    
    if(pid == -1)
    {
        printf("ERROR IN PROCESS CREATION \n");
        exit(1);
    }
    
    if(pid != 0)
    {
        pid1 = getpid();
        printf("\nthe parent process ID is %d\n", pid1);
    }
    else
    {
        pid2 = getpid();
        printf("\nthe child process ID is %d\n", pid2);
    }
    
    return 0;
}


//the parent process ID is 26219

//the child process ID is 26220

