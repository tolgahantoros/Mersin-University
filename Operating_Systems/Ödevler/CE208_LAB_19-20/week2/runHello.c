#include<stdio.h>
#include<unistd.h>

int main(){
	execl("hello", "hello", NULL);
	printf("runHello.c\n");
}

/*
$ gcc runHello1.c -o runHello1
$ ./runHello1

*/
