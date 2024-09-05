#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	
	pid_t pid; //ozel pid degiskeni
	printf("First Process ID: %d \n", (int)getpid());

	pid = fork();

	//fork(); //2n kadar process olusur her cagirimda

	printf("Return value: %d \n", pid);
	printf("After forkk() Process ID: %d \n", (int)getpid());
	
	return 0;

}
