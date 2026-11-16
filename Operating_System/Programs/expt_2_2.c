#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <process.h>
#define getpid _getpid
#else
#include <unistd.h>
#endif

int main(int argc, char *argv[])
{
    /* Windows starts a fresh copy of this program as the child. */
    if (argc > 1 && strcmp(argv[1], "child") == 0) {
        printf("Child process ID: %d\n", getpid());
        return 0;
    }

    printf("Parent process ID: %d\n", getpid());
    fflush(stdout);

#ifdef _WIN32
    const char *child_args[] = { argv[0], "child", NULL };

    if (_spawnv(_P_WAIT, argv[0], child_args) == -1) {
        perror("spawn");
        return 1;
    }
#else
    {
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            return 1;
        }
        if (pid == 0)
            printf("Child process ID: %d\n", getpid());
    }
#endif

    return 0;
}
