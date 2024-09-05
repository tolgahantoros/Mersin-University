//Passing arguments to a thread

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *merhaba(void *args){
	char *str = (char *)args; //argüman void olarak tanımlandığı için cast edilmesi gerek
	printf("%s", str);
}

int main(){
	pthread_t thread;

	char *yazi = "Merhaba Dunya\n";
	
	//create a new thread and have it run the function merhaba()
	pthread_create(&thread, NULL, merhaba, yazi);
	
	//wait until the thread completes
	pthread_join(thread, NULL);
	
	return 0;
}

/*
compile: 
	$ gcc -lpthread thread6.c -o thread6

run:
	$ ./thread6

This time we set up the function merhaba to take the argument yazi,
a string containing the phrase "Merhaba Dunya\n".

Note that in the startup routine, it must take a void * argument,
so we have to cast 
	char *str = (char *) args;

The result of calling pthread_create() is that the new thread executes:
	merhaba(yazi);
*/

