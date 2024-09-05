//Return values from threads

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>

void *merhaba(void *args){
	//allocate a new string on the heap with "Merhaba Dunya"
	//char *str = strdup("Merhaba Dunya\n");
	char *str = "Merhaba Dunya\n";
  
	return (void *) str;
}

int main(){
	pthread_t thread;

	char *yazi;

	
	//create a new thread that returns merhaba without arguments
	pthread_create(&thread, NULL, merhaba, NULL);
		
	//wait until the thread completes, assign return value to yazi
	pthread_join(thread, (void **) &yazi);

	printf("Thread'den donen deger: %s", yazi);

	return 0;
}

/*
$ gcc -pthread thread8.c -o thread8

The startup routine returned a void * which is really a reference to the string containing
"Merhaba Dunya".

The reference to the string is stored at yazi and printed to the string.

The string str in the thread is allocated on the heap and the reference to that string is 
provided in the main program.
That means "the thread and the main thread are sharing resources", namely memory.

Sharing memory occurs for threads naturally and enables a lot of powerful programming paradigms.
It also creates new challenges.
What happens when two threads try and write to the same memory at the same time?
*/

