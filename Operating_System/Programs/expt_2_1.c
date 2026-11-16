#include <stdio.h>
#include <dirent.h>

int main(void)
{
    char path[256];
    struct dirent *entry;
    DIR *dir;

    printf("Enter directory name: ");
    if (scanf("%255s", path) != 1) {
        fprintf(stderr, "No directory name given.\n");
        return 1;
    }

    dir = opendir(path);
    if (dir == NULL) {
        perror(path);
        return 1;
    }

    while ((entry = readdir(dir)) != NULL)
        printf("%s\n", entry->d_name);

    closedir(dir);
    return 0;
}
