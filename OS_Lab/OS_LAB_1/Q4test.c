#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char const *argv[])
{
    char ch;
    int fd[2];
    int status = pipe(fd);
    int o2 = open("output2.txt",O_WRONLY,0644);
    switch(fork()){
        case -1:    
        exit(0);
        case 0:
        close(fd[1]);
        while(read(fd[0],&ch,1)==1)write
        close(fd[0]);
        break;
        default:
        close(fd[0]);
        write(fd[1],"Modi",4);
        close(fd[1]);
    }
    return 0;
}
