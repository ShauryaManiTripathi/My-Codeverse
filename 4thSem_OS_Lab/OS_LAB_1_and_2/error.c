#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include <errno.h>
void exit(int); /* gets rid of warning message */
main(int argc, char *argv[])
{
    if (open(argv[1], O_RDONLY) < 0)
    {
        fprintf(stderr, "errno=%d\n", errno);
        perror("open error in main");
    }
    exit(0);
}