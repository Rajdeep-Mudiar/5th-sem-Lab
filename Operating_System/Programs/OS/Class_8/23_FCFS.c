// 23)Write a C program for implementation of FCFS scheduling algorithm.

#include<stdio.h>
#include<stdlib.h>

struct fcfs
{
    int pid;
    int btime;
    int wtime;
    int ttime;
} p[10];

int main()
{
    int i, n;
    int totwtime = 0, totttime = 0;
    
    printf("\nfcfs scheduling...\n");
    printf("enter the no of process: ");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        printf("\nburst time of the process %d: ", i + 1);
        scanf("%d", &p[i].btime);
    }

    p[0].wtime = 0;
    p[0].ttime = p[0].btime;
    totttime += p[0].ttime;

    for(i = 1; i < n; i++)
    {
        p[i].wtime = p[i-1].wtime + p[i-1].btime;
        p[i].ttime = p[i].wtime + p[i].btime;
        totttime += p[i].ttime;
    }

    for(i = 0; i < n; i++)
    {
        totwtime += p[i].wtime;
        printf("\nProcess %d:", p[i].pid);
        printf("\nWaiting time: %d", p[i].wtime);
        printf("\nTurnaround time: %d\n", p[i].ttime);
    }

    printf("\nTotal waiting time : %d", totwtime);
    printf("\nAverage waiting time : %f", (float)totwtime / n);
    printf("\nTotal turnaround time : %d", totttime);
    printf("\nAverage turnaround time : %f\n", (float)totttime / n);

    return 0;
}



//fcfs scheduling...
//enter the no of process: 3

//burst time of the process 1: 2

//burst time of the process 2: 4

//burst time of the process 3: 3

//Process 1:
//Waiting time: 0
//Turnaround time: 2

//Process 2:
//Waiting time: 2
//Turnaround time: 6

//Process 3:
//Waiting time: 6
//Turnaround time: 9

//Total waiting time : 8
//Average waiting time : 2.666667
//Total turnaround time : 17
//Average turnaround time : 5.666667

