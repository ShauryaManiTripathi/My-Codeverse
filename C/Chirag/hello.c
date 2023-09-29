#include<stdio.h>
#include<stdlib.h>

struct hellow{
    int left;
    float right;
};
int main(int argc, char const *argv[])
{
    struct hellow s1={1,2.0};
    struct hellow *s2=&s1;
    printf("%d,%f\n",s1.left,s1.right);
    printf("%d,%f",(*s2).left,(*s2).right);
    return 0;
}
