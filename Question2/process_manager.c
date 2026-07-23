#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed.\n");
        return 1;
    }

    if (pid == 0) {
        printf("Child Process: PID = %d\n", getpid());
        printf("Child is working...\n");
        sleep(10);
        printf("Child finished.\n");
        exit(0);
    } else {
        printf("Parent Process: PID = %d\n", getpid());

        sleep(3);

        printf("Checking child process...\n");

        kill(pid, SIGTERM);

        wait(NULL);

        printf("Child process terminated and cleaned up.\n");
    }

    return 0;
}
