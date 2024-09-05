#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	
	pid_t pid;	//fork'dan geri donen degeri pid degiskeninde tutacagim

	printf("fork() cagirmadan once calisan prosesin ID'si: %d\n", (int) getpid());

	pid = fork();

	// programimizi derleyip calistirdigimizda bu satirdan sonra:
	// cagri basarisiz olursa fork() fonksiyonundan geriye -1 degeri doner, 
	// cocuk proses olusmaz
	
	if (pid < 0)
		perror("fork hatasi\n");
		
	// cagri basarili olursa
	// fork()'u cagiran prosesin birebir kopyasi olan bir cocuk proses olusur
	// programin bundan sonraki kismi hem anne hem de cocuk proses icin ayri ayri calisir
	// hangisinin once calisacagina isletim sistemi karar verir

	printf("fork'dan geriye donen deger : %d\n", (int) pid);

	printf("Su an calisan prosesin ID'si : %d\n", (int) getpid());	

	return 0;
}

/*
Calistirmak icin:
 $ gcc  lab4prog3.c -o lab4prog3
 $ ./lab4prog3

Bu programda fork() sistem cagrisini kullanarak yeni bir proses olusturacagiz.

fork() sistem cagrisi : Bu fonksiyonu cagiran prosesin birebir kopyasi olan bir cocuk proses olusturur.
 
   pid_t fork(void);

fork() sistem cagrisi <unistd.h> kutuphanesinde tanimlidir. Bu fonksiyonu kullanabilmek icin programimizin basina 
	#include <sys/types.h>
	#include <unistd.h>
eklemeliyiz.
	
*/

