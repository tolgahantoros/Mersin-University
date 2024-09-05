/* Named pipe: a server program */
/* Usage: progname pipename & */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*#define FIFONAME    "myfifo" */

int
main(int argc, char * argv[])

{
    int n, fd;
    char buf[1024];

    /*
     * Remove any previous FIFO.
     */
    unlink(argv[1]);

    /*
     * Create the FIFO.
     */
    if (mkfifo(argv[1], 0666) < 0) {
        perror("mkfifo");
        exit(1);
    }

    /* Make sure that the mode of the pipe is really 0666 */
    if(chmod(argv[1], 0666) < 0) {perror("chmod"); exit(1);}

    /*
     * Open the FIFO for reading.
     * The server will block here until the client starts...
     */
    if ((fd = open(argv[1], O_RDONLY)) < 0) {
        perror("open");
        exit(1);
    }

    
    while ((n = read(fd, buf, sizeof(buf))) > 0)
        write(1, buf, n);

    close(fd);
    exit(0);
}
