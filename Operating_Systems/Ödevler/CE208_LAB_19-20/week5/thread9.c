//Passing data to a thread

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *f(void *args){
	int num = * (int *) args;
	printf("Thread %d calisiyor\n", num);
	pthread_exit(NULL);
}

int main(){
	pthread_t threads[4];
	int nums[4];
	int i;

	for(i = 0; i < 4; i++){
		nums[i] = i;
		pthread_create(&threads[i], NULL, f, &nums[i]);
	}

	
	//wait for the threads to finish
	for(i = 0; i < 4; i++){
		pthread_join(threads[i], NULL);
	}

	return 0;
}

/*
$ gcc -pthread thread9.c -o thread9

Here we pass a pointer to an int and then cast it as a void *.
This is done so that any type of data can be passed into a thread.

*/

