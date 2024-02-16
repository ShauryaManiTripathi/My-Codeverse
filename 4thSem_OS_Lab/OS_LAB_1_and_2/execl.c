#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    // Create a child process
    pid_t pid = fork();

    if (pid == 0)
    {
        // Child process
        printf("This is the child process, pid = %d\n", getpid());

        // Replace the child process image with the "/bin/ls" command image
        // The arguments are the command itself and its parameters
        // The list of arguments must be terminated by a NULL pointer
        execl("/bin/ls", "ls", "-l", NULL);

        // If execl returns, there was an error
        perror("execl failed");
    }
    else if (pid > 0)
    {
        // Parent process
        printf("This is the parent process, pid = %d, child pid = %d\n", getpid(), pid);
    }
    else
    {
        // Fork failed
        perror("fork failed");
    }

    return 0;
}

// The `execl` function in C is used to replace the current process image with a new process image. It takes the following arguments:

// 1. `path`: This is a string that specifies the path to the file that will be executed. This file should be a binary executable, or a script starting with a line of the form `#!interpreter [arg]`.

// 2. `arg0`, `arg1`, ..., `argn`: These are strings that represent the argument list to be passed to the new process image. The first argument, by convention, should point to the filename associated with the file being executed. The list of arguments must be terminated by a NULL pointer.

// 3. `NULL`: This is used to indicate the end of the argument list.

// In the provided code, `execl("/bin/ls", "ls", "-l", NULL);` is used to replace the current process image with the `/bin/ls` command image. The arguments `"ls"` and `"-l"` are passed to the new process image. The argument list is terminated by `NULL`.

// If `execl` is successful, it does not return. If it does return, there was an error, and the error message is printed using `perror`.