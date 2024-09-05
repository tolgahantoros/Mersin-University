/* Named pipe: a client program */
/* Usage: progname pipename */
/*    or: progname pipename < text-file */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* #define FIFONAME    "myfifo" */

int
main(int argc, char * argv[])

{
    int n, fd;
    char buf[1024];

    if ((fd = open(argv[1], O_WRONLY)) < 0) {
        perror("open");
        exit(1);
    }

   
    while ((n = read(0, buf, sizeof(buf))) > 0)
        write(fd, buf, n);

    close(fd);
    exit(0);
}
