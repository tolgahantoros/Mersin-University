#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	
	pid_t pid = fork();

	if(pid == 0){
		sleep(3);
		wait(NULL);
		printf("child-1 id: %d parent id:%d \n", getpid(), getppid());
		printf("parent id: %d \n", getppid());
		exit(0);
	}
	
	pid = fork();
	if(pid == 0){
		sleep(2);
		wait(NULL);
		printf("child-2 id: %d parent id:%d \n", getpid(), getppid());
		exit(0);
	}
	
	pid = fork();
	if(pid == 0){
		sleep(1);
		wait(NULL);
		printf("child-3 id: %d parent id:%d \n", getpid(), getppid());
		exit(0);
	}
	
	pid = fork();
	if(pid == 0){
		printf("child-4 id: %d parent id:%d \n", getpid(), getppid());
		exit(0);
	}

	for(int i=0; i<5; i++){
		wait(NULL);
	}
	

	return 0;
}
