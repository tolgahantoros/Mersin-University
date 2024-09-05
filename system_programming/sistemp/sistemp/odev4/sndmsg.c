// C Program for Message Queue (Writer Process)
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 10

/*structure for message queue
struct mesaj_buf {
	long tip;;
	char *mesaj[7]="Merhaba";
} message;*/

int tip;
char mesaj[7]="Merhaba";
int i=0;
int main()
{
	key_t key;
	int msgid;
    
	for(;;)
    {
	key = rand() % 100 + 1;     
   	msgid = msgget(key, 0666 | IPC_CREAT);
	tip = 1;
	msgsnd(msgid,1,mesaj[i], 0);
    printf("Gönderilen Bilgi: %c \n", mesaj[i]);    
    i++;
    sleep(5);
    if (i==7) i=0;    

    }
	return 0;
}

