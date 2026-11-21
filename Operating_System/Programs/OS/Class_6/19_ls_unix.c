// 19)PROGRAM FOR SIMULATION OF LS UNIX COMMANDS 

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char **argv)
{
    DIR *dp;
    struct dirent *link;
    
    if(argc < 2)
    {
        printf("Please provide a directory name\n");
        exit(1);
    }
    
    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Cannot open directory\n");
        exit(1);
    }
    
    printf("\n contents of the directory %s are \n", argv[1]);
    
    while((link = readdir(dp)) != NULL)
    {
        printf("%s\n", link->d_name);
    }
    
    closedir(dp);
    return 0;
}

//gcc ls_unix.c
//./a.out .
// contents of the directory . are 
//a.out
//cp_unix.c
//..
//unix2.c
//index.html
//FCFS.c
//unix1.c
//.
//ls_unix.c
//round_robin.c

