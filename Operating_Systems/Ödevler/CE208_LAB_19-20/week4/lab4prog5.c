#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	
	pid_t pid;	//fork'dan geri donen degeri pid degiskeninde tutacagim

	printf("fork() cagirmadan once calisan prosesin ID'si: %d\n", (int) getpid());
	
	pid = fork();

	if (pid < 0)
		perror("fork hatasi\n");
		
	if (pid == 0){
		printf("Merhaba ben cocuk proses. Process ID = %d\n", (int) getpid());
		
		//cocuk prosesi 5 saniye uyutuyorum, boylece anne prosesin cocuk prosesten once calismasini saglayacagim
		sleep(5); 
		
		printf("Cocuk proses sonlaniyor...\n");
		exit(0);
	}
	else if (pid > 0){
		printf("Merhaba ben anne proses.Process ID = %d\n", (int) getpid());
		printf("Cocuk prosesin bitmesini bekliyorum.\n");
		wait(NULL);	// anne proses cocuk proses bitene kadar bekleyecek
		printf("Anne proses sonlaniyor...\n");
	}			

	return 0;
}

/*
Calistirmak icin:
 $ gcc  lab4prog5.c -o lab4prog5
 $ ./lab4prog5

Bu programda kullandigimiz yeni fonksiyonlar:

  $ man 3 exit
    #include <stdlib.h>
    void exit(int status);
  
 $ man 3 sleep
    #include <unistd.h>
    unsigned int sleep(unsigned int seconds);

 $ man 2 wait 
    #include <sys/types.h>
    #include <sys/wait.h>
    pid_t wait(int *status);
    pid_t waitpid(pid_t pid, int *status, int options);	
*/

