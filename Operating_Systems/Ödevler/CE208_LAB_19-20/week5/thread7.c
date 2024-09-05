//Joining threads

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *merhaba(void *args){
	printf("Merhaba Dunya\n");
}

int main(){
	pthread_t thread;
	
	//create a new thread and have it run the function merhaba()
	pthread_create(&thread, NULL, merhaba, NULL);
		
	return 0;
}

/*
$ gcc -pthread thread7.c -o thread7

Just like with processes, it is often useful to be able to identify when a thread has completed or exited.
The method for doing this is to join the thread, which is a lot like the wait() call for the processes.
Joining is a blocking operation, and the calling thread will not continue until the thread 
identified has changed states.
Typically, only the main thread calls join, but other threads can also join each other.
All threads are automatically joined when the main thread terminates.
the above code produces no output.
The program fails to join the new thread before the main thread terminated. As a result,
the thread was automatically joined and did not have a chance to print "Merhaba Dunya"

The fact that you do not have to join threads is actually an advantage because once
the main thread dies the entire process dies.
There are no zombies, no wasted resources. It all just comes to a hault.
*/

