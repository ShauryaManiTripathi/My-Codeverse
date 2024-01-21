#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main() {
    int fd = open("file.txt", O_RDONLY); // Open a file for reading
    int new_fd = dup(fd); // Duplicate the file descriptor

    // Now you can use both 'fd' and 'new_fd' to read from the file

    close(fd);
    close(new_fd);
    return 0;
}