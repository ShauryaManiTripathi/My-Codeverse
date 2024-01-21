#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<errno.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        if(argv[i][0]!='-')puts(argv[i]);
    }
    
    return 0;
}

