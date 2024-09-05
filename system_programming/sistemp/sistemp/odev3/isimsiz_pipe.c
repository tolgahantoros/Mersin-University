#include <stdio.h>
#include <unistd.h>
main ()
{
char buf[128];
int fd[2]; /* 2 isimsiz pipe belirteçleri için dizi değişken */
int pid; /* Proses kimliklerini tutan değişken*/
/* Bir pipe herhangi bir forkden önce yaratılmalı*/
/*Bunun neden böyle olduğunuz analdınız mı */
if (pipe(fd) < 0)
{perror ("Pipe oluşturma hatası");
exit (1);
}
pid = fork (); /* Parent: 1. çocuk prosesi oluşturdu */
if (pid == 0) /* ikinci çocuk proses burda başlatılıyor*/
{dup2 (fd[1],1); /* Standard çıkış pipe ın yazma ucuna konacak */
close (fd[0]); /* Bu işlem süresince okuma ucu kapalı olacak, kullanılmaycak */
write(fd[1],"bu\n",3);
write(fd[1],"mesaj\n",6);
write(fd[1],"geri\n",5);
write(fd[1],"donmeli\n",8);
close(fd[1]);   

}
else /* Parent proses devam ediyor*/
pid = fork (); /* Parent: 2. çocuk prosesi oluşturdu  */
if (pid == 0) /* üçüncü çocuk proses burda başlatılıyor*/
{dup2 (fd[1],1); /* Standard çıkış pipe ın yazma ucuna konacak */
close (fd[0]); /* Bu işlem süresince okuma ucu kapalı olacak, kullanılmaycak */
write(fd[1],"2.\n",3);
write(fd[1],"ç2\n",3);
write(fd[1],"y2\n",3);
write(fd[1],"yaz2\n",5);
close(fd[1]);


}

else
pid = fork (); /* Parent: 3. çocuk prosesi oluşturdu  */
if (pid == 0) /* İlk çocuk proses burda başlatılıyor */
{
dup2 (fd[0],0); /* Standart giriş, pipe ın okuma ucundan alınacak */
close (fd[1]); /* Pipe yazma ucu bu işlem için kapatılacak, kullanılmayacak */
while(read(fd[0],buf,sizeof(buf))>0)
{read(fd[0],buf,sizeof(buf));
write(1,buf,sizeof(buf));
}
close(fd[0]);


}


else /* Ana işlem pipe uçlarını kendisi için kapatıp çocuk prosesleri bekler */
{
close (fd[0]);
close (fd[1]);
wait (0);
wait (0);
}
}
