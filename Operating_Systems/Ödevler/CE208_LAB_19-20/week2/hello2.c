#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[]){
	int i;
	
	printf("arguman sayisi: %d\n", argc);
	
	printf("argumanlar: ");
	for(i=0; i<argc;i++){
		printf("%s, ", argv[i]);
	}
	printf("\n");
	return 0;
}

/*
$ gcc hello2.c -o hello2

$ ./hello2

$ ./hello2 a1

$ ./hello2 a1 a2 a3

*/
