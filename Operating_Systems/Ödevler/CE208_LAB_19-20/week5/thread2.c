#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *merhaba(){
	printf("Merhaba, bu bir thread cagrisidir.\n");
	pthread_exit(0);	//****
}

int main(){
	pthread_t thread;

	//create a new thread and have it run the function merhaba()
	pthread_create(&thread, NULL, merhaba, NULL);
	
	printf("Thread'in sonlanmasini bekliyorum...\n");

	//wait until the thread completes
	pthread_join(thread, NULL);

	printf("Thread sonlandi.\n");
	
	return 0;
}	
	
/*
compile: 
	$ gcc -lpthread thread2.c -o thread2

run:
	$ ./thread2

manual:
	$ man pthread_exit

*/
