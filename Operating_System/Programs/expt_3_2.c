#include <stdio.h>
#include <string.h>

#define MAX_LINE 1024

int main(int argc, char *argv[])
{
    char line[MAX_LINE];
    FILE *fp;
    int line_no = 0;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file> <word>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror(argv[1]);
        return 1;
    }

    while (fgets(line, sizeof line, fp) != NULL) {
        line_no++;
        line[strcspn(line, "\n")] = '\0';   /* remove trailing newline */

        if (strstr(line, argv[2]) != NULL)
            printf("%s:%d: %s\n", argv[1], line_no, line);
    }

    fclose(fp);
    return 0;
}
