#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#include<stdbool.h>
#include<sys/wait.h>
#include<fcntl.h>

int leafList[10];
int leafIndex = 0;

int handleInput(int argN, const char *path, const char *leafNum) {
    if (argN != 3) {
        return 3;
    }
    int itmp = atoi(leafNum);
    if (1 > itmp || 10 < itmp) {
        return 4;
    }
    FILE *tmp = fopen(path, "r");
    if (tmp != NULL) {
        fclose(tmp);
        return 5;
    }

    return 0;
}

void printInFile(FILE *file) {
    fprintf(file, "%i\n", getpid());
    fflush(file);
}

void managerHandler(int sigNum, siginfo_t * info) {
    switch (sigNum) {
        case SIGUSR1:
            if (leafIndex >= 0) {
                    union sigval sender_pid;
                    sender_pid.sival_int=info->si_pid;
                    sigqueue(leafList[leafIndex], SIGUSR1, sender_pid);

                kill(leafList[leafIndex], SIGTERM);
                leafIndex--;
            }
            else{
                kill(getpid(), SIGKILL);
            }
            break;

        case SIGTERM:
            while (leafIndex > 0) {
                kill(leafList[leafIndex], SIGTERM);
                leafIndex--;
            }
            kill(getpid(), SIGKILL);
            break;
    }
}

void leafHandler(int sigNum, siginfo_t * info) {
    if(sigNum==SIGUSR1){
        kill(info->si_value.sival_int,SIGUSR2);
    }
}

void proliferate(FILE *file, int leafNum) {
    printInFile(file);
    int manager = fork();
    if (manager == 0) {
        printInFile(file);
        for (int i = 0; i < leafNum; i++) {
            int leaf = fork();
            if (leaf == 0) {
                printInFile(file);
                
                struct sigaction sa;
                sa.sa_flags = SA_SIGINFO;
                sa.sa_handler = leafHandler;
                sigemptyset(&sa.sa_mask);
                sigaction(SIGUSR1, &sa, NULL);
                //sigaddset(&sa.sa_mask, SIGCHLD);
                //sigaddset(&sa.sa_mask, SIGCONT);
                signal(SIGCHLD, SIG_IGN);
                signal(SIGCONT, SIG_IGN);
                
                while (1) {
                    pause();
                }
            } else {
                leafList[leafIndex] = leaf;
                leafIndex++;
            }
        }
        if(leafIndex>0){
            leafIndex--;
        }
        

        
        //signal(SIGUSR1, managerHandler);
        //signal(SIGTERM, managerHandler);
        signal(SIGALRM, SIG_IGN);

        struct sigaction sa;
        sa.sa_flags = SA_SIGINFO;
        sa.sa_handler = managerHandler;
        sigemptyset(&sa.sa_mask);
        //sigaddset(&sa.sa_mask, SIGALRM);
        sigaction(SIGUSR1, &sa, NULL);
        sigaction(SIGTERM, &sa, NULL);

        while (1) {
            pause();
        }
    }
}

int main(int argc, char const *argv[]) {
    int inputHandlerCode = handleInput(argc, argv[1], argv[2]);

    if (inputHandlerCode != 0) {
        exit(inputHandlerCode);
    }

    int leafNum;
    sscanf(argv[2], "%d", &leafNum);

    FILE *file = fopen(argv[1], "a");

    proliferate(file, leafNum);

    return 0;
}
