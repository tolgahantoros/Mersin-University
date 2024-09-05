#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	
	pid_t pid;	//fork'dan geri donen degeri pid degiskeninde tutacagim

	printf("fork() cagirmadan once calisan prosesin ID'si: %d\n", (int) getpid());

	// Bir onceki programda fork() fonksiyonunu calistirdiktan sonra geriye donen degerleri ekrana yazdirdik.
	// fork()'dan geriye donen degeri kullanarak anne ve cocuk proses icin farkli kodlar yazabiliriz.
	
	pid = fork();

	if (pid < 0)
		perror("fork hatasi\n");
		
	// programin bundan sonraki kismi hem anne hem de cocuk proses icin ayri ayri calisir
	// hangisinin once calisacagina isletim sistemi karar verir
	// o an calisan proses icin pid degeri 0(sifir) ise cocuk proses calisiyordur.
	// pid 0(sifir) dan buyuk ise anne proses calisiyordur.
	// Bunun icin pid degerini kontrol edecegiz

	if (pid == 0){
		printf("Merhaba ben cocuk proses\n");
		printf("Process ID = %d\n", (int) getpid());
	}
	else if (pid > 0){
		printf("Merhaba ben anne proses\n");
		printf("Process ID = %d\n", (int) getpid());
	}			

	return 0;
}

/*
Calistirmak icin:
 $ gcc  lab4prog4.c -o lab4prog4
 $ ./lab4prog4
	
*/

