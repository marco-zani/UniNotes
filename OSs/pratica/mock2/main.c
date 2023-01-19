
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdbool.h>
#include<signal.h>

int childCount = 0;
int childArray[10];
const char *path;


int checkFile(const char *path) {
    int res = 0;
    FILE *file = fopen(path, "r");
    if (file != NULL) {
        res = 1;
        fclose(file);
    }
    
    return res;
}

void writeLog() {
    FILE *file = fopen(path, "a");
    fprintf(file, "%i\n", getpid());
    fflush(file);
    fclose(file);
}

void writeSymbol(char c, int child) {
    FILE *file = fopen(path, "a");
    if(childCount > 0){
        fprintf(file, "%c%i\n", c, child);
    }
    else{
        fprintf(file, "0\n");
    }
    
    fflush(file);
    fclose(file);
}

void serverHandler(int sigNum) {
    int childID = 0;
    switch (sigNum) {
        case SIGUSR1:
            childID = fork();
            if (childID == 0) {
            } else {
                childArray[childCount] = childID;
                childCount++;
                printf("[server] +%i\n", childID);
                fflush(stdout);
                writeSymbol('+', childID);
            }
            break;
        case SIGUSR2:
            if(childCount>0){
                childCount--;
                childID = childArray[childCount];
                kill(childID, SIGTERM);

                printf("[server] -%i\n", childID);
                fflush(stdout);
            
            }
            else{
                printf("[server] 0\n");
                fflush(stdout);
            }
            writeSymbol('-', childID);
            
            break;
        case SIGINT:
            FILE *f = fopen(path, "a");
            fprintf(f, "%i\n", childCount);
            fflush(f);
            fclose(f);
            kill(getpid(), SIGTERM);
            break;
    }
}

int serverMode() {

    if (checkFile(path) == 1) {
        return 1;
    }
    FILE *file = fopen(path, "w");
    
    fclose(file);
    
    writeLog();
    printf("[server:%i]\n", getpid());

    signal(SIGUSR1, serverHandler);
    signal(SIGUSR2, serverHandler);
    signal(SIGINT, serverHandler);


    while (1) {
        pause();
    }
}

int clientMode(){
    printf("[client]\n");
    int serverPID = -1;
    
    FILE * f = fopen(path, "r");
    while (f == NULL)
    {
        sleep(1);
        f = fopen(path, "r");
    }

    fscanf(f, "%d\n", &serverPID);
    printf("[client] server: %i\n", serverPID);
    fflush(stdout);

    char c;
    while (1)
    {
        c = getchar();
        switch(c){
            case '+':
            if(childCount < 10){
                kill(serverPID, SIGUSR1);
                childCount++;
            }
            
             break;
            case '-': 
            if(childCount > 0){
                kill(serverPID, SIGUSR2);
                childCount--;
            }break;
            case '\n': break;
        }
    }
    
        
}

int main(int argc, char const *argv[]) {
    int status = 0;
    path = argv[2];
    
    if (strcmp(argv[1], "server")) {
        status = clientMode();
    } else {
        
        status = serverMode();
    }

    printf("%i",status);
    return status;
}
