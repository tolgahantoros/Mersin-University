#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
	
	pid_t pid;

	pid = fork();

	if(pid == 0){
		printf("Hello, I'm child\n");
		printf("ID:%d\n", (int)getpid());
		sleep(5);
		exit(0);	
	}

	
	wait(NULL);	//parent, child'in sonlanmasini bekleyecek
	printf("I'm parent\n");
	printf("ID:%d\n", (int)getppid());
	
	return 0;

}
