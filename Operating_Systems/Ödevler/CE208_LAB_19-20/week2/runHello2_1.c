#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[]){

	char *args[] = {"./hello2", "Hello", "World", NULL};
	
	execvp("./hello2", args);	
	printf("exec sonrasi \n");
	return 0;
}

/*

$ gcc runHello2_1.c -o runHello2_1
$ ./runHello2_1

*/
