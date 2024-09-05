#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int y = 120; 	//global degisken

int main(){
	
	pid_t pid;	
	
	int x = 4;	//local degisken

	printf("fork() cagirmadan once calisan prosesin ID'si: %d\n", (int) getpid());
	printf("y global degiskeninin fork'dan onceki degeri y = %d\n\n", y);
	printf("x local degiskeninin fork'dan onceki degeri x = %d\n\n", x);
	
	pid = fork();

	if (pid < 0)
		perror("fork hatasi\n");
		
	if (pid == 0){
		printf("Merhaba ben cocuk proses. Process ID = %d\n", (int) getpid());
		
		//cocuk proseste y'nin degerini 10 arttiriyorum						
		y = y + 10;
		printf("y global degiskeninin cocuk prosesteki degeri y = %d\n", y);

		//cocuk proseste x'in degerini 2 arttiriyorum						
		x = x + 2;						
		printf("x local degiskeninin cocuk prosesteki degeri x = %d\n", x);

		printf("Cocuk proses sonlaniyor...\n\n");
		exit(0);
	}
	else if (pid > 0){
		printf("Merhaba ben anne proses.Process ID = %d\n", (int) getpid());

		//anne proseste y'nin degerini 25 arttiriyorum						
		y = y + 25;
		printf("y global degiskeninin anne prosesteki degeri y = %d\n", y);
		
		//anne proseste x'in degerini 5 arttiriyorum
		x = x + 5;
		printf("x local degiskeninin anne prosesteki degeri x = %d\n", x);

		printf("Cocuk prosesin bitmesini bekliyorum.\n\n");
		wait(NULL);	// anne proses cocuk proses bitene kadar bekleyecek
		printf("Anne proses sonlaniyor...\n");
	}			

	return 0;
}

/*
Calistirmak icin:
 $ gcc  lab4prog6.c -o lab4prog6
 $ ./lab4prog6


*/

