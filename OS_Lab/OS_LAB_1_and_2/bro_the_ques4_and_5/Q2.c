#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(int argc, char const *argv[])
{   
    int non_alpha=0;
    char ch;
    ch=getchar();
    while(ch!=EOF){
        if(!isalpha(ch))non_alpha++;
        putchar(ch);
        ch=getchar();
    }
    fprintf(stderr,"%d\n",non_alpha);
    exit(0);
    return 0;
}
