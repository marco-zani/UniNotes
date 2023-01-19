#include <pthread.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

const char *path;

void logPrint(int sigN, int pid) {
    FILE *file = fopen(path, "a");

    switch (sigN) {
        case SIGUSR1:
            sleep(3);
            fprintf(file, "%d-%d\n", pid, SIGUSR1);
            fflush(file);
            fclose(file);
            break;
        case SIGUSR2:
            sleep(3);
            fprintf(file, "%d-%d\n", pid, SIGUSR2);
            fflush(file);
            fclose(file);
            break;
        case SIGINT:
            fprintf(file, "stop\n");
            fflush(file);
            fclose(file);
            break;
    }
}

void proxyHandler(int sigNum, siginfo_t *info) {
    int sender = info->si_pid;
    
    switch (sigNum) {
        case SIGUSR1:            
            kill(SIGUSR1, sender);
            logPrint(SIGUSR1, sender);
            break;
        case SIGUSR2:
            if (fork() == 0) {
                kill(sender, SIGUSR2);
                logPrint(SIGUSR2, sender);
                exit(0);
            }
            break;
        case SIGINT:
            logPrint(SIGINT, -1);
            exit(0);
            break;
    }
}

int main(int argc, char const *argv[]) {

    path = argv[1];

    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_handler = proxyHandler;

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    sigaction(SIGINT, &sa, NULL);

    while (1) {
        pause();
    }

    return 0;
}
