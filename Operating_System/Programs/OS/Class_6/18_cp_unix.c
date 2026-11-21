// 18)Program for simulation of cp unix commands 

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int ch;
    int sc = 0;
    
    if (argc < 2)
    {
        printf("Please provide a filename\n");
        exit(1);
    }
    
    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("unable to open a file\n");
        exit(1);
    }
    else
    {
        while ((ch = fgetc(fp)) != EOF)
        {
            if (ch == ' ')
                sc++;
        }
        printf("no of spaces %d\n", sc);
        fclose(fp);
    }
    
    return 0;
}

//gcc cp_unix.c
//./a.out FCFS.c
//no of spaces 297

