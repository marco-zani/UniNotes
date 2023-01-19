#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define P_WRITE 1
#define P_READ 0

int PIPES_N = 2;


int main() {
    int pipes[PIPES_N][2];
    char child_buff[50], parent_buff[50];

    for (int i = 0; i < PIPES_N; i++) {
        pipe(pipes[i]);
    }

    if(fork()){
        //child
        close(pipes[0][P_WRITE]);
        close(pipes[1][P_READ]);

        read(pipes[0][P_READ], &child_buff, 50);
        printf("child-read: %s\n", child_buff);
        fflush(stdout);

        printf("writing to parent\n");
        fflush(stdout);
        write(pipes[1][P_WRITE], "message to parent", 18);
    }
    else{
        //parent
        close(pipes[0][P_READ]);
        close(pipes[1][P_WRITE]);

        printf("writing to child\n");
        fflush(stdout);
        write(pipes[0][P_WRITE], "message to child", 17);

        read(pipes[1][P_READ], &parent_buff, 50);
        printf("parent-read: %s\n", parent_buff);
        fflush(stdout);
    }
}
