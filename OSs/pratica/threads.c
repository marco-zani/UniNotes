#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t l_glob_var;
int glob_var = 10;

void *waister() {
    printf("I'm waisting your time\n");
    sleep(2);
    
}

void * conc1(){
    pthread_mutex_lock(&l_glob_var);
    glob_var = 20;
    sleep(1);
    glob_var++;
    printf("concurrent 1 sees %d\n", glob_var);
    fflush(stdout);
    pthread_mutex_unlock(&l_glob_var);
}
void * conc2(){
    pthread_mutex_lock(&l_glob_var);
    glob_var = 5;
    sleep(1);
    glob_var++;
    printf("concurrent 2 sees %d\n", glob_var);
    fflush(stdout);
    pthread_mutex_unlock(&l_glob_var);
}

void main() {
    pthread_t first_t, second_t;
    int arg = 10;
    pthread_create(&first_t, NULL, waister, NULL);

    sleep(2);

    pthread_join(first_t, NULL);
    //pthread_cancel(first_t);
    //printf("thread deleted\n");

    printf("thread waited\n");

    pthread_t conc1_t, conc2_t;
    
    pthread_mutex_init(&l_glob_var,NULL);
    pthread_create(&conc1_t, NULL, conc1, NULL);
    pthread_create(&conc2_t, NULL, conc2, NULL);

    sleep(4);

    pthread_mutex_destroy(&l_glob_var);

}
