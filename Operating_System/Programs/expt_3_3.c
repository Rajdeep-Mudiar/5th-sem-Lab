#include <stdio.h>
#include <string.h>

#define MAX_LINE 1024

int main(int argc, char *argv[])
{
    char line[MAX_LINE];
    const char *pattern;
    FILE *fp;
    int line_no = 0;
    int occurrences = 0;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file> <pattern>\n", argv[0]);
        return 1;
    }

    pattern = argv[2];
    if (*pattern == '\0') {
        fprintf(stderr, "Pattern cannot be empty.\n");
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror(argv[1]);
        return 1;
    }

    while (fgets(line, sizeof line, fp) != NULL) {
        char *match = line;
        int line_occurrences = 0;

        line_no++;
        while ((match = strstr(match, pattern)) != NULL) {
            line_occurrences++;
            occurrences++;
            match += strlen(pattern);
        }

        if (line_occurrences > 0) {
            line[strcspn(line, "\n")] = '\0';
            printf("%s:%d: %s\n", argv[1], line_no, line);
        }
    }

    fclose(fp);
    printf("Total occurrences of \"%s\": %d\n", pattern, occurrences);

    return 0;
}
