#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	
	pid_t pid;
	printf("Waiting...\n");
	sleep(1);
	pid = fork();

	if(pid == 0){
		printf("Hello, I'm child\n");
		printf("ID:%d\n", (int)getpid());
		printf("Waiting for child...\n");
		sleep(2);
		exit(0);	
	}

	
	wait(NULL);	//parent, child'in sonlanmasini bekleyecek
	printf("I'm parent\n");
	printf("ID:%d\n", (int)getppid());
	
	return 0;

}
