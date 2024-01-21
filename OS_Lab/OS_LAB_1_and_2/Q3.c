#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    char ch;
    ch = getchar();
    while (ch != EOF)
    {
        if(isalpha(ch)){
            if(ch>='a'){
                ch-=32;
            }
            else{
                ch+=32;
            }
        }
        putchar(ch);
        ch = getchar();
    }
    return 0;
}
