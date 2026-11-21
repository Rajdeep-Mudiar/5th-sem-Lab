// 25) Write a C-program to implement the producer – consumer problem using semaphores.

#include <stdio.h>
#include <stdlib.h>

int mutex = 1, full = 0, empty = 3, x = 0;

int main() {
    int n;
    void producer();
    void consumer();
    int wait(int);
    int signal(int);
    
    printf("\n1.PRODUCER\n2.CONSUMER\n3.EXIT\n");
    
    while (1) {
        printf("\nENTER YOUR CHOICE\n");
        scanf("%d", &n);
        
        switch (n) {
            case 1:
                if ((mutex == 1) && (empty != 0))
                    producer();
                else
                    printf("BUFFER IS FULL");
                break;

            case 2:
                if ((mutex == 1) && (full != 0))
                    consumer();
                else
                    printf("BUFFER IS EMPTY");
                break;
                
            case 3:
                exit(0);
                break;
        }
    }
    return 0;
}

int wait(int s) {
    return (--s);
}

int signal(int s) {
    return (++s);
}

void producer() {
    empty = wait(empty);
    mutex = wait(mutex);
    x++;
    printf("\nproducer produces the item%d", x);
    mutex = signal(mutex);
    full = signal(full);
}

void consumer() {
    full = wait(full);
    mutex = wait(mutex);
    printf("\n consumer consumes item%d", x);
    x--;
    mutex = signal(mutex);
    empty = signal(empty);
}


//1.PRODUCER
//2.CONSUMER
//3.EXIT

//ENTER YOUR CHOICE
//1

//producer produces the item1
//ENTER YOUR CHOICE
//1

//producer produces the item2
//ENTER YOUR CHOICE
//1

//producer produces the item3
//ENTER YOUR CHOICE
//1
//BUFFER IS FULL
//ENTER YOUR CHOICE
//2

 //consumer consumes item3
//ENTER YOUR CHOICE
1

//producer produces the item3
//ENTER YOUR CHOICE
//3







