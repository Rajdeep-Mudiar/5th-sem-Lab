// 24)Write a C program for implementation of SJF scheduling algorithm.

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int pid;
    int btime;
    int wtime;
} sp;

int main()
{
    int i, j, n, tbm = 0, totwtime = 0, totttime = 0;
    sp *p, t;
    
    printf("\n sjf scheduling ..\n");
    printf("enter the no of processes: ");
    scanf("%d", &n);
    
    p = (sp *)malloc(n * sizeof(sp));
    
    printf("\n enter the burst time:\n");
    for(i = 0; i < n; i++)
    {
        printf("process %d: ", i + 1);
        scanf("%d", &p[i].btime);
        p[i].pid = i + 1;
        p[i].wtime = 0;
    }
    
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(p[i].btime > p[j].btime)
            {
                t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        }
    }
    
    printf("\n process \tburst time \twaiting time \tturnaround time\n");
    for(i = 0; i < n; i++)
    {
        totwtime += p[i].wtime = tbm;
        tbm += p[i].btime;
        printf("\n%d\t\t%d", p[i].pid, p[i].btime);
        printf("\t\t%d\t\t%d", p[i].wtime, p[i].wtime + p[i].btime);
    }
    
    totttime = tbm + totwtime;
    printf("\n\ntotal waiting time : %d", totwtime);
    printf("\naverage waiting time : %f", (float)totwtime / n);
    printf("\ntotal turnaround time : %d", totttime);
    printf("\naverage turnaround time : %f\n", (float)totttime / n);
    
    free(p);
    return 0;
}



 //sjf scheduling ..
//enter the no of processes: 3

 //enter the burst time:
//process 1: 5
//process 2: 2
//process 3: 8

 //process 	burst time 	waiting time 	turnaround time

//2		2		0		2
//1		5		2		7
//3		8		7		15

//total waiting time : 9
//average waiting time : 3.000000
//total turnaround time : 24
//average turnaround time : 8.000000



