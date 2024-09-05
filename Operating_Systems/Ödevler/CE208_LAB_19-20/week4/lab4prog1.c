#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	
	pid_t pid;	

	pid = getpid();

	printf("Process ID = %d\n", (int) pid);

	return 0;
}

/*
Bu programda getpid() sistem cagrisini kullanarak, programi derleyip calistirdigimizda 
olusan prosese isletim sistemi tarafindan verilen proses id'sini ekrana yazdiriyoruz.

Programi home/ce208/lab4 dizinine kaydediyoruz.
Programi komut satirindan derleyip icin calistirmak:
  $ cd /home/ce208/lab4
  $ gcc  lab4prog1.c -o lab4prog1
  $ ./lab4prog1
Programi birkac kez calistirdigimizda her seferinde farkli bir process ID yazdigini goreceksiniz.
  $ ./lab4prog1
  $ ./lab4prog1


Bilmemiz gerekenler : 
  pid_t : Process ID icin kullanilan ozel bir veri tipi 
	  (GNU C kutuphanesinde int'e karsilik gelir, 
	   printf icinde %d ile yazdirabiliriz, 
	  (int) kullanarak cast etmek daha garantili olur) 
	  Bunu kullaniyorsak programimizin basina #include<sys/types.h> eklemeliyiz.

  getpid() sistem cagrisi :
	prototipi :
		pid_t getpid(void);
	
	Bu fonksiyon kendisini cagiran prosesin "Process ID" sini verir.
	
*/

