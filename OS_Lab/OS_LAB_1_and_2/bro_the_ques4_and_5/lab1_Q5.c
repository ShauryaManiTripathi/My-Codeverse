#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int test1 = 1, test2 = 1, fd1, fd2;
    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0]!='-')
        {
            if (test1 == 1)
            {
                fd1 = open(argv[i], O_RDONLY);
                if (fd1 == -1)
                {
                    fprintf(stderr, "Error: Failed to open file %s\n", argv[i]);
                    exit(1);
                }
                test1 = 0;
            }
            else if (test2 == 1)
            {
                fd2 = creat(argv[i], O_WRONLY);
                if (fd2 == -1)
                {
                    fprintf(stderr, "Error: Failed to create file %s\n", argv[i]);
                    exit(1);
                }
                test2 = 0;
            }
            else
            {
                break;
            }
        }
        else
        {
            continue;
        }
    }

    if (test1 && test2)
    {
        fprintf(stderr, "the arguments werent enough to open a input and output file");
        exit(1);
    }
    
    // Duplicate file descriptors to stdin and stdout
    if (dup2(fd1, STDIN_FILENO) == -1)
    {
        fprintf(stderr, "Error: Failed to duplicate file descriptor for stdin\n");
        exit(1);
    }
    if (dup2(fd2, STDOUT_FILENO) == -1)
    {
        fprintf(stderr, "Error: Failed to duplicate file descriptor for stdout\n");
        exit(1);
    }

// Create a pipe
    int pipefd[2];
    if (pipe(pipefd) == -1)
    {
        fprintf(stderr, "Error: Failed to create pipe\n");
        exit(1);
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Parent process
    // Close both ends of the pipe
    close(pipefd[0]);
    close(pipefd[1]);
// Fork the first child
    pid_t child1 = fork();
    if (child1 == -1)
    {
        fprintf(stderr, "Error: Failed to fork first child\n");
        exit(1);
    }
    else if (child1 == 0)
    {
// Child 1 process
        // Close the write end of the pipe
        close(pipefd[1]);
// Duplicate the read end of the pipe to stdin
        if (dup2(pipefd[0], STDIN_FILENO) == -1)
        {
            fprintf(stderr, "Error: Failed to duplicate file descriptor for stdin\n");
            exit(1);
        }

// Execute the count program
        execl("./count", "count", NULL);

// If execl fails, print an error message
        fprintf(stderr, "Error: Failed to execute count program\n");
        // Close the read end of the pipe
        close(pipefd[0]);
        exit(0);
    }
        // Fork the second child
    pid_t child2 = fork();
    if (child2 == -1)
    {
        fprintf(stderr, "Error: Failed to fork second child\n");
        exit(1);
    }
    else if (child2 == 0)
    {
        // Child 2 process
        // Close the read end of the pipe
        close(pipefd[0]);

        // Duplicate the write end of the pipe to stdout
        if (dup2(pipefd[1], STDOUT_FILENO) == -1)
        {
            fprintf(stderr, "Error: Failed to duplicate file descriptor for stdout\n");
            exit(1);
        }

        // Execute the convert program
        execl("./convert", "convert", NULL);

        // If execl fails, print an error message
        fprintf(stderr, "Error: Failed to execute convert program\n");
        // Close the write end of the pipe
        close(pipefd[1]);
        exit(0);
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // if (fork() != 0)
    // { /* parent continues here */
    //     if (fork() != 0)
    //     {
    //         /* parent continues here */
    //         // Parent process
    //         // Close both ends of the pipe
    //         close(pipefd[0]);
    //         close(pipefd[1]);
    //         // Wait for both children to finish
    //         wait(NULL);
    //         wait(NULL);
    //     }
    //     else
    //     {
    //         // Child 2 process
    //         // Close the read end of the pipe
    //         close(pipefd[0]);

    //         // Duplicate the write end of the pipe to stdout
    //         if (dup2(pipefd[1], STDOUT_FILENO) == -1)
    //         {
    //             fprintf(stderr, "Error: Failed to duplicate file descriptor for stdout\n");
    //             exit(1);
    //         }

    //         // Execute the convert program
    //         execl("/path/to/convert", "convert", NULL);

    //         // If execl fails, print an error message
    //         fprintf(stderr, "Error: Failed to execute convert program\n");
    //         // Close the write end of the pipe
    //         close(pipefd[1]);
    //         exit(0);
    //     }
    // }
    // else
    // {
    // }
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Wait for both children to finish
    wait(NULL);
    wait(NULL);
    // Close the file descriptors
    close(fd1);
    close(fd2);

    return 0;
}
