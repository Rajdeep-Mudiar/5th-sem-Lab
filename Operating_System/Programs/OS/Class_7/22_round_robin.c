// 22)Write a C program for implementation of Round Robin scheduling algorithm. 

#include<stdio.h>
#include<stdlib.h>

struct rr
{
int pno,btime,sbtime,wtime,lst;
}p[10];

int main(){

    int pp=-1,ts,flag,count,ptm=0,i,n,twt=0,totttime=0;
    printf("\n round robin scheduling............");
    printf("enter no of processes:");
    scanf("%d",&n);
    printf("enter the time slice:");
    scanf("%d",&ts);
    printf("enter the burst time");
    
    for(i=0;i<n;i++){
    printf("\n process%d\t",i+1);
    scanf("%d",&p[i].btime);
    p[i].wtime=p[i].lst=0;
    p[i].pno=i+1;
    p[i].sbtime=p[i].btime;
    }

    printf("scheduling....\n");
    do {
    flag=0;
    
    for(i=0;i<n;i++){
    count=p[i].btime;
    if(count>0){
    flag=-1;
    count=(count>=ts)?ts:count;
    printf("\n process %d",p[i].pno);
    printf("from%d",ptm);
    ptm+=count;
    printf("to%d",ptm);
    p[i].btime-=count;
    if(pp!=i){
    pp=i;
    p[i].wtime+=ptm-p[i].lst-count;
    p[i].lst=ptm;
    }
    }
    }
    } while(flag != 0);

    return 0;
}




// round robin scheduling............enter no of processes:2
//enter the time slice:2
//enter the burst time
 //process1	3

 //process2	4
//scheduling....

 //process 1from0to2
 //process 2from2to4
 //process 1from4to5

