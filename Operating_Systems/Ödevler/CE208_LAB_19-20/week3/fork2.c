#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	
	pid_t pid; //ozel pid degiskeni

	pid = fork();

	if(pid == 0){
		printf("Hello, I'm child\n");	
	}
	else if(pid>0){
		printf("I'm parent\n");
	}
	
	return 0;

}
