// 20) PROGRAM FOR SIMULATION OF GREP UNIX COMMANDS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 1024

void usage()
{
    printf("usage:\t./a.out filename word \n");
}

int main(int argc, char *argv[])
{
    FILE *fp;
    char fline[max];
    char *newline;
    int count = 0;
    int occurrences = 0;
    
    if(argc != 3)
    {
        usage();
        exit(1);
    }
    
    if(!(fp = fopen(argv[1], "r")))
    {
        printf("grep: could not open file : %s \n", argv[1]);
        exit(1);
    }
    
    while(fgets(fline, max, fp) != NULL)
    {
        count++;
        if((newline = strchr(fline, '\n')) != NULL)
            *newline = '\0';
            
        if(strstr(fline, argv[2]) != NULL)
        {
            printf("%s: %d %s \n", argv[1], count, fline);
            occurrences++;
        }
    }
    
    fclose(fp);
    return 0;
}

//gcc grep_unix.c
//./a.out grep_unix.c could
//grep_unix.c: 28         printf("grep: could not open file : %s \n", argv[1]); 

