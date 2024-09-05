#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/syscall.h>

void *merhaba(){
	pthread_t td = pthread_self();

	printf("merhaba : Thread ID = %d,  Process ID = %d, Pthread ID = %lu \n", (pid_t)syscall(SYS_gettid), (int)getpid(), td);
	pthread_exit(0);
}

int main(){
	pthread_t thread;
	
	//create a new thread and have it run the function merhaba()
	pthread_create(&thread, NULL, merhaba, NULL);
	
	printf("main : Thread ID = %d,  Process ID = %d\n", (pid_t)syscall(SYS_gettid), (int)getpid());	

	//wait until the thread completes
	pthread_join(thread, NULL);
	
	return 0;
}

/*

compile: 
	$ gcc -lpthread thread5.c -o thread5

run:
	$ ./thread5

A thread id is a lot like a process id. 
In fact, for the main program, the thread id is process id.
For a new thread, the thread id is different, but it returns the process id of the main program. 
*/	
	

