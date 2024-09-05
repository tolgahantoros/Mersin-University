#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[]){

	char *args[] = {"./hello2", "Hello", "World", NULL};
	
	execvp(args[0], args);
	
	printf("exec sonrasi \n");
	return 0;
}

/*

$ gcc runHello2_2.c -o runHello2_2
$ ./runHello2_2

*/
