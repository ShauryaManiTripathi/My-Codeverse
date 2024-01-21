#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    pipe(fd); // Create a pipe

    int pid = fork(); // Create a child process

    if (pid == 0) {
        // Child process
        close(fd[0]); // Close the read end of the pipe

        // Write data to the write end of the pipe
        write(fd[1], "Hello from child shauyra!", 25);

        close(fd[1]); // Close the write end of the pipe
    } else {
        // Parent process
        close(fd[1]); // Close the write end of the pipe

        char buffer[100];
        // Read data from the read end of the pipe
        read(fd[0], buffer, sizeof(buffer));

        printf("Received message from child process: %s\n", buffer);

        close(fd[0]); // Close the read end of the pipe
    }

    return 0;
}