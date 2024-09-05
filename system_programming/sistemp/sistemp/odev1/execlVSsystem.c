#include <sys/types.h>
#include <unistd.h>
int main(void) {
pid_t pid;
char *args[4];

/*
* Bu kodu sadece parent işletecek
*/
/* burada execv için parametreleri hazırlıyor ..execv exec ailesinin başka bir üyesi*/
args[0] = "date";
args[1] = "+Date = %D Time = %H:%M";
args[2] = NULL;
for(int i=1;i<50000;i++){}  
execv("/bin/date", args);
/*
* eğer exec başarılı ise buraya gelmeyecektir..
*/
perror("exec failed in parent");

exit(1);

if ((pid = fork()) < 0) {
perror("fork failed");
exit(1);
}
if (pid == 0) {
execl("/bin/echo", "echo", "Today's", "date", "is:", 0);
/*
* eğer exec başarılı ise buraya gelmeyecektir.
*/
perror("exec failed in child");

exit(1);
}



}
