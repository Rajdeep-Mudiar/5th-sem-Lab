#include <stdio.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    struct dirent *entry;
    DIR *dir;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    dir = opendir(argv[1]);
    if (dir == NULL) {
        perror(argv[1]);
        return 1;
    }

    printf("Contents of %s:\n", argv[1]);
    while ((entry = readdir(dir)) != NULL)
        printf("%s\n", entry->d_name);

    closedir(dir);
    return 0;
}
