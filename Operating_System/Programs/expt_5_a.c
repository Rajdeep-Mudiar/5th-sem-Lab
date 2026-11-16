#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

struct process {
    int pid;
    int priority;
    int burst;
    int wait;
    int turnaround;
};

static int by_priority(const void *a, const void *b)
{
    const struct process *x = a;
    const struct process *y = b;

    if (x->priority != y->priority)
        return x->priority - y->priority;   /* smaller number = higher priority */
    return x->pid - y->pid;                 /* keep input order for ties */
}

int main(void)
{
    struct process p[MAX_PROCESSES];
    int n, i, elapsed = 0;
    int total_wait = 0;
    int total_turnaround = 0;

    printf("Priority scheduling\nEnter number of processes: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_PROCESSES) {
        fprintf(stderr, "Enter a number between 1 and %d.\n", MAX_PROCESSES);
        return 1;
    }

    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Process %d (burst time priority): ", p[i].pid);
        if (scanf("%d %d", &p[i].burst, &p[i].priority) != 2 ||
            p[i].burst < 1) {
            fprintf(stderr, "Invalid input.\n");
            return 1;
        }
    }

    qsort(p, n, sizeof p[0], by_priority);

    for (i = 0; i < n; i++) {
        p[i].wait = elapsed;
        p[i].turnaround = elapsed + p[i].burst;
        elapsed += p[i].burst;
        total_wait += p[i].wait;
        total_turnaround += p[i].turnaround;
    }

    printf("\nPID  Priority  Burst  Wait  Turnaround\n");
    for (i = 0; i < n; i++)
        printf("%3d  %8d  %5d  %4d  %10d\n",
               p[i].pid, p[i].priority, p[i].burst,
               p[i].wait, p[i].turnaround);

    printf("\nTotal waiting time    : %d\n", total_wait);
    printf("Average waiting time  : %.2f\n", (double)total_wait / n);
    printf("Total turnaround time : %d\n", total_turnaround);
    printf("Average turnaround    : %.2f\n", (double)total_turnaround / n);

    return 0;
}
