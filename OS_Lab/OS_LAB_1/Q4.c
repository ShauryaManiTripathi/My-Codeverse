// Q. Write C programs to know the use of following system calls 1. open()
// 2. creat()
// 3. dup()
// 4. dup2()
// 5. pipe()
// 6. read()
// 7. write()
// close()
// unlink()

#include <stdio.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>

#define INFILE "input.txt"
#define OUTFILE "output.txt"
#define INFILE2 "input2.txt"
#define OUTFILE2 "output2.txt"
#define RANDOMFILE "random.txt"

int main(int argc, char const *argv[])
{
    // creat() creates a file with the given name and returns a file descriptor
    // file descriptor is an integer that uniquely identifies an open file of the process
    // creat() is equivalent to open() with flags = O_CREAT|O_WRONLY|O_TRUNC
    // file descriptor is 0 for stdin, 1 for stdout, 2 for stderr
    // creat() returns -1 on error
    // 0644 is the permission for the file which is read and write for the owner and read for the group and others
    // the permission for read only is 0444
    //int fi1 = open(INFILE,02);  // read and write
    int fi2 = open("input2.txt", 02); // read and write
    //int fo1 = open(OUTFILE, O_WRONLY); 
    int fo2 = creat("output2.txt", 0644);   // read and write for owner, read for group and others

    // dup() duplicates the file descriptor
    // dup() returns the lowest numbered unused file descriptor
    // dup() returns -1 on error
    // dup2() duplicates the file descriptor and uses the given file descriptor instead of the lowest numbered unused file descriptor
    // dup2() returns the given file descriptor
    // dup2() returns -1 on error
    //  int fi1_dup = dup(fi1);
    //  int fi2_dup = dup2(fi2,fi1);
    //  int fo1_dup = dup(fo1);
    //  int fo2_dup = dup2(fo2,fo1);
    //  int fr_dup = dup(fr);

    // use read() and write() to read and write from the file descriptor
    // read() returns the number of bytes read
    // read() returns 0 on end of file
    // read() returns -1 on error
    // write() returns the number of bytes written
    // write() returns -1 on error
    char c[10] = "1234567890";
    #define BUFSIZ 1024
    char buf[BUFSIZ];
    int n;
    while ((n = read(0, buf, BUFSIZ)) < 5)
        write(1, buf, n);

    // show use of read() and write()
    // while (read(fi1, &ch, 1) == 1)
    // {
    //     write(fo1, &ch, 1);
    //     count++;
    // }
    //unlink() deletes the file
    //close() closes the file descriptor
    //close() returns 0 on success
    //close() returns -1 on error

    char x[1];
    //write(fi2, c, 10);
    //lseek(fi2, 0, SEEK_SET);
    while (read(fi2, x, 1) == 1)
    {
        write(fo2, x, 1);
    }
    //pipe() creates a pipe and returns two file descriptors
    //where are these two file descriptor stored?
    //pipe() returns -1 on error
    //pipe() returns 0 on success
    //pipe() returns the file descriptors in the array
    //pipe() returns the read file descriptor in the first element of the array
    //pipe() returns the write file descriptor in the second element of the array
    //show use of pipe()
    int fd[2];
    pipe(fd);
    int pid = fork();
    if (pid == 0)
    {
        close(fd[0]);
        write(fd[1], "hello", 5);
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        char buf[10];
        read(fd[0], buf, 10);
        printf("%s\n", buf);
        close(fd[0]);
    }
    return 0;

}
