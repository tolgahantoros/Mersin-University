#include <stdio.h>
#include <unistd.h>
main ()
{
char buf[128];
int f1[2]; /* 2 isimsiz pipe belirteçleri için dizi değişken */
int f2[2];
int pid; /* Proses kimliklerini tutan değişken*/
/* Bir pipe herhangi bir forkden önce yaratılmalı*/
/*Bunun neden böyle olduğunuz analdınız mı */
if (pipe(f1) < 0)
{perror ("Pipe oluşturma hatası");
exit (1);
}

if (pipe(f2) < 0)
{perror ("Pipe oluşturma hatası");
exit (1);
}

pid = fork ();
if (pid == 0) 
{dup2 (f2[1],1); 
close (f2[0]); 
write(f2[1],"bu\n",3);
write(f2[1],"mesaj\n",6);
write(f2[1],"geri\n",5);
write(f2[1],"donmeli\n",8);
close(f2[1]);

dup2 (f1[0],0); 
close (f1[1]); 
while(read(f1[0],buf,sizeof(buf))>0)
{read(f1[0],buf,sizeof(buf));
write(1,buf,sizeof(buf));
}
close(f1[0]);
}
else /* Parent proses devam ediyor*/
pid = fork (); 
if (pid == 0) 
{
dup2(f2[0],0); 
close (f2[1]); 
dup2(f1[1],1);
close (f1[0]); 

while(read(f2[0],buf,sizeof(buf))>0)
{read(f2[0],buf,sizeof(buf));
write(f1[1],buf,sizeof(buf));
}
close(f2[0]);
close(f1[1]);
}

else /* Ana işlem pipe uçlarını kendisi için kapatıp çocuk prosesleri bekler */
{
close (f1[0]);
close (f1[1]);
close (f2[0]);
close (f2[1]);
wait (0);
wait (0);
}
}
