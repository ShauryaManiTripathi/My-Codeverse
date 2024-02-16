#include <stdio.h>

int main() {
    if (unlink("file.txt") == 0) {
        printf("File deleted successfully.\n");
    } else {
        printf("Failed to delete the file.\n");
    }

    return 0;
}

// #include <stdio.h>
// #include <unistd.h>

// int main() {
//     int fd = open("file.txt", O_RDONLY); // Open a file for reading

//     // Perform operations on the file

//     close(fd); // Close the file descriptor

//     return 0;
// }