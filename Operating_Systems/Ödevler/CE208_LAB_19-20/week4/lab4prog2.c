#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	
	printf("Process ID = %d\n", (int) getpid());
	
	printf("Parent(Anne) Process ID = %d\n", (int) getppid());

	return 0;
}

/*
Bu programda getppid() sistem cagrisini kullanarak, prosesin parent(anne, ebeveyn) prosesinin ID'sini yazdiriyoruz.

Bilmemiz gerekenler : 
  pid_t : Process ID icin kullanilan ozel bir veri tipi 
	  (GNU C kutuphanesinde int'e karsilik gelir, 
	   printf icinde %d ile yazdirabiliriz, 
	  (int) kullanarak cast etmek daha garantili olur) 
	  Bunu kullaniyorsak programimizin basina #include<sys/types.h> eklemeliyiz.

  getppid() sistem cagrisi :
	prototipi :
		pid_t getppid(void);
	 
	Bu fonksiyon kendisini cagiran prosesin parent(anne) prosesinin "Process ID" sini verir.
	
*/

