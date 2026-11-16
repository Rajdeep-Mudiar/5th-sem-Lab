#include <stdio.h>

#define BUFFER_SIZE 3

int mutex = 1;
int full = 0;
int empty = BUFFER_SIZE;
int item = 0;

static int wait_sem(int s)   { return s - 1; }
static int signal_sem(int s) { return s + 1; }

static void produce(void)
{
    mutex = wait_sem(mutex);
    empty = wait_sem(empty);
    full = signal_sem(full);

    printf("Producer produced item %d\n", ++item);

    mutex = signal_sem(mutex);
}

static void consume(void)
{
    mutex = wait_sem(mutex);
    full = wait_sem(full);
    empty = signal_sem(empty);

    printf("Consumer consumed item %d\n", item--);

    mutex = signal_sem(mutex);
}

int main(void)
{
    int choice;

    while (1) {
        printf("\n1. Produce\n2. Consume\n3. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1)
            break;

        switch (choice) {
        case 1:
            if (empty > 0)
                produce();
            else
                printf("Buffer is full.\n");
            break;
        case 2:
            if (full > 0)
                consume();
            else
                printf("Buffer is empty.\n");
            break;
        case 3:
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
