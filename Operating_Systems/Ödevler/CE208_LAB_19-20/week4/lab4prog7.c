#include <stdio.h>	// printf() icin gerekli
#include <unistd.h>	//exec() cagrisi icin gerekli

int main(){

	execl("/bin/ls", "ls", "-l", NULL);

	printf("Bunu okuyorsaniz execl() sistem cagrisi basarisiz olmustur!\n");
	return 0;
}

/*

Programi derleyip calistirmak icin :
	$ gcc lab4prog7.c -o lab4prog7
	$ ./lab4prog7

exec grubu sistem çağrıları yürütme(execute) işlemlerini gerçekleştirmek için kullanılır.
Bu gruptaki fonksiyonlar ile ilgili bilgilere "man 3 exec" komutu ile ulaşabilirsiniz.

Programın başına #include<unistd.h> eklenmeli.

Örneğin komut satırından çalıştırdığımız

    $ ls -l

komutunu exec grubundaki fonksiyonlardan birini kullanarak program içerisinden çalıştırabiliriz.


Bu programda kullandigimiz execl() fonksiyonunun prototipi :
  
  int execl(const char *path, const char *arg, ... (char  *) NULL);

Fonksiyonun ilk parametresi olarak çalıstıracagimiz komutun adini yolu ile birlikte yazmamiz gerekiyor.
ls komutu /bin altinda bulunur.

Programi komut satirindan calistirirken yazdigimiz her kelimeyi ayri bir parametre olarak sirasiyla fonksiyona ekliyoruz. 

Son parametre olarak da NULL yazmamiz gerekiyor.

Ornegin ls -l execl komutunu() fonksiyonuyla calistirmak istedigimizde parametreleri:

    execl("/bin/ls", "ls", "-l", NULL);

seklinde girmemiz gerekiyor. 

exec() grubu fonksiyonlari yalnizca hata durumunda -1 degerini dondurur. 

Calistirilan komut basarili olursa geriye donus olmaz (onemli!!!!).

*/

