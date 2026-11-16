#include <stdio.h>

#define MAX_PROCESSES 10

struct process {
    int pid;
    int burst;
    int wait;
    int turnaround;
};

int main(void)
{
    struct process p[MAX_PROCESSES];
    int n, i;
    int total_wait = 0;
    int total_turnaround = 0;

    printf("FCFS scheduling\nEnter number of processes: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_PROCESSES) {
        fprintf(stderr, "Enter a number between 1 and %d.\n", MAX_PROCESSES);
        return 1;
    }

    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Burst time of process %d: ", p[i].pid);
        if (scanf("%d", &p[i].burst) != 1 || p[i].burst < 0) {
            fprintf(stderr, "Invalid burst time.\n");
            return 1;
        }

        p[i].wait = (i == 0) ? 0 : p[i - 1].wait + p[i - 1].burst;
        p[i].turnaround = p[i].wait + p[i].burst;
        total_wait += p[i].wait;
        total_turnaround += p[i].turnaround;
    }

    printf("\nPID  Burst  Wait  Turnaround\n");
    for (i = 0; i < n; i++)
        printf("%3d  %5d  %4d  %10d\n",
               p[i].pid, p[i].burst, p[i].wait, p[i].turnaround);

    printf("\nTotal waiting time    : %d\n", total_wait);
    printf("Average waiting time  : %.2f\n", (double)total_wait / n);
    printf("Total turnaround time : %d\n", total_turnaround);
    printf("Average turnaround    : %.2f\n", (double)total_turnaround / n);

    return 0;
}
