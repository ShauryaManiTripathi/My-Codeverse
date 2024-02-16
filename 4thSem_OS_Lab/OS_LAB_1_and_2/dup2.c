#include <stdio.h>
#include <unistd.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>


int main() {
    int fd = open("file.txt", O_RDONLY); // Open a file for reading
    int new_fd = open("new_file.txt", O_WRONLY | O_CREAT, 0644); // Open a new file for writing

    dup2(new_fd, fd); // Duplicate 'new_fd' to 'fd'

    // Now any write operations on 'fd' will write to 'new_file.txt'

    close(fd);
    close(new_fd);
    return 0;
}
int main() {
    int fd = open("file.txt", O_RDONLY); // Open a file for reading
    int new_fd = open("new_file.txt", O_WRONLY | O_CREAT, 0644); // Open a new file for writing

    dup2(new_fd, fd); // Duplicate 'new_fd' to 'fd'

    // Now any write operations on 'fd' will write to 'new_file.txt'

    close(fd);
    close(new_fd);
    return 0;
}