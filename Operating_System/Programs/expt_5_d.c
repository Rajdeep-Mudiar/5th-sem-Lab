#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

struct process {
    int pid;
    int burst;
    int wait;
    int turnaround;
};

static int by_burst(const void *a, const void *b)
{
    const struct process *x = a;
    const struct process *y = b;

    return (x->burst > y->burst) - (x->burst < y->burst);
}

int main(void)
{
    struct process p[MAX_PROCESSES];
    int n, i, elapsed = 0;
    int total_wait = 0;
    int total_turnaround = 0;

    printf("SJF scheduling\nEnter number of processes: ");
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
    }

    qsort(p, n, sizeof p[0], by_burst);

    for (i = 0; i < n; i++) {
        p[i].wait = elapsed;
        p[i].turnaround = elapsed + p[i].burst;
        elapsed += p[i].burst;
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
