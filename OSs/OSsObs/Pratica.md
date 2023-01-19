# Processes
## Fork
```C
int children = fork();
//children sees 0, parent sees manager pid
if (children == 0) {
	...
	while(1){pause();}
} else {
	...
}
```
## Pipes
```C
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
		close(pipes[0][P_WRITE]); //closing unused comunication lines
		close(pipes[1][P_READ]); //Usually self-write and non-self-reads
		  
		read(pipes[0][P_READ], &child_buff, 50);
		printf("child-read: %s\n", child_buff);
		fflush(stdout);
	}
	else{
		//parent
		close(pipes[0][P_READ]);
		close(pipes[1][P_WRITE]);
		  
		printf("writing to child\n");
		fflush(stdout);
		write(pipes[0][P_WRITE], "message to child", 17);
	}
}
```
# Signals
## Bind signal and handler
```C
signal(SIGCHLD, handler);
signal(SIGCHLD, SIG_IGN);
```
## Send signal
```C
kill(leafList[leafIndex], SIGTERM);
```
## Signal handler
```C
void signalHandler(int sigNum, siginfo_t * info) {
	switch (sigNum) {
		case SIGUSR1:
			...
		break;
		  
		case SIGTERM:
			...
		break;
	}
}
```
## Sigaction
```C
struct sigaction sa;
sa.sa_handler = signalHandler;
sigemptyset(&sa.sa_mask);
//bind handler
sigaction(SIGUSR1, &sa, NULL);
//block signals
sigaddset(&sa.sa_mask, SIGCHLD);
sigaddset(&sa.sa_mask, SIGCONT);
```
## Retrieving the sender pid
```C
//sigaction
{
	struct sigaction sa
	sa.sa_flags = SA_SIGINFO;
	...
}

void handler(itn sigNum, siginfo_t * info){
	printf("%d", info->si_pid);
}
```
## Sending data with signals
```C
//sender
union sigval data;
data.sival_int= ...;
//and/or
data.sival_ptr = ...;
sigqueue(pid, SIGURS1, data);

//receiver
void receiverHandler(int sigNum, siginfo_t * info) {
	if(sigNum==SIGUSR1){
		printf("%d", info->si_value.sival_int);
	}
}
```
# Threads
## Starting a thread
```C
void * my_fun() {...}

void main() {
	pthread_t thread;
	
	pthread_create(&thread, NULL, my_fun, NULL);
}
```
## Thread with params
```C
 void *my_fun(void *param) {
	 printf("This is a thread that received %d\n", *(int *)param);
 }

void main() {
	pthread_t thread;
	int arg = 10;
	pthread_create(&thread, NULL, my_fun, (void *)&arg);
}
```
## Managing threads
```C
pthread_t thread;

pthread_join(pthread_t thread, void ** retval);
...

pthread_cancel(thread);
```
## Mutex
#### creating mutex
```C
//variable and lock
pthread_mutex_t l_glob_var;
int glob_var;

void main() {
	pthread_t conc1_t, conc2_t;
	pthread_mutex_init(&l_glob_var,NULL);
	...
	pthread_mutex_destroy(&l_glob_var);
}
```
#### Using mutex
```C
void * conc1(){
	pthread_mutex_lock(&l_glob_var);
	... //critical section
	pthread_mutex_unlock(&l_glob_var);
}
```
# Utils
## Input handler
```C
int handleInput(int argN, const char *path, const char *leafNum) {
	if (argN != 3) {
		return 3;
	}
	int itmp = atoi(leafNum);
	if (1 > itmp || 10 < itmp) {
		return 4;
	}
	FILE *tmp = fopen(path, "r");
	//check if file exists
	if (tmp != NULL) {
		fclose(tmp);
		return 5;
	}
	return 0;
}
```
## Libraries
```C
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
```
## Makefile
```makefile
NAME=program

$(NAME):main.c
@gcc -o $(NAME) main.c
```
#### Makefile with path search
```makefile
DEST=""
  
SHELL=/bin/bash
  
.SILENT: help
  
.PHONY: help
  
help:
[ ${DEST} = "" ] && gcc main.c -o coda -std=gnu90 || ( [[ -e ${DEST} ]] && gcc main.c -o ${dest}/coda -std=gnu90 || echo "?ERROR" )
```
## Bash
```bash
#!/bin/bash
if [ $# -ne 2 ]; then
	echo "Wrong number of paramethers"
	else
	if [ -f $1 ]; then
		rm $1
	fi
	make
	./program $1 $2
	cat $1
fi
```
## Print in file
```C
void writeLog() {
	FILE *file = fopen(path, "a");
	fprintf(file, "%i\n", getpid());
	fflush(file);
	fclose(file);
}
```

## Check file
```C
int checkFile(const char *path) {
	int res = 0;
	FILE *file = fopen(path, "r");
	if (file != NULL) {
		res = 1;
		fclose(file);
	}
	return res;
}
```

## Read from file
```C
FILE * f = fopen(path, "r");
while (f == NULL)
{
	sleep(1);
	f = fopen(path, "r");
}
  
fscanf(f, "%d\n", &serverPID);
printf("[client] server: %i\n", serverPID);
fflush(stdout);
```
## Compare strings
```C
if (strcmp(argv[1], "server")) {
	status = clientMode();
} else {
	status = serverMode();
}
```