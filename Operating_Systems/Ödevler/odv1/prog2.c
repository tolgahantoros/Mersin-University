#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	
	FILE *fp;
	pid_t pid = fork();


	if(pid == 0){
		printf("1. \"sampledir\" createing...\n");
		execl("/bin/mkdir", "mkdir", "sampledir", NULL);
		exit(0);
	}


	wait(NULL);
	printf("  >created.\n");
	pid = fork();
	if(pid == 0){
		printf("2. \"simpledir/simplefile1.txt\" creating...\n");
		execl("/bin/touch", "touch", "sampledir/samplefile1.txt", NULL);
		exit(0);
	}


	wait(NULL);
	printf("  >created.\n");
	pid = fork();
	if(pid == 0){
		printf("3. \"simplefile1.txt\" writing...\n");
		fp = fopen("sampledir/samplefile1.txt", "w");
		fprintf(fp, "17-155-025\nMustafa YOLUK\n");
		fclose(fp);
		exit(0);
	}

	
	wait(NULL);
	printf("  >wrote.\n");
	pid = fork();
	if(pid == 0){
		printf("4. \"simplefile1.txt\" reading...\n\n");
		execl("/bin/cat", "cat", "sampledir/samplefile1.txt", NULL);
		exit(0);
	}

	
	wait(NULL);
	printf("\n  >read.\n\n");
	exit(0);


	
	return 0;
}
