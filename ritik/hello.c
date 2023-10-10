#include<stdio.h>

struct triplet{
    int a;
    float b;
    double c;
};
void printer(int* a){
    *a=10;
    printf("%u\n",*a);
}

int main(){
    struct triplet t;
    
    t.a = 50000;
    int b = t.a;
    t.b= 5.5;
    t.c = 5.6;
    //printf("%u\n",&t.a);
    printer(&t.a);
    printf("%d\n",t.a);
    //printf("%7d %2.3f %lf\n", t.a, t.b, t.c);
    //printf("%07d %d\n", b,t.a);

    struct triplet t2={4,5.5,6.6};

    int array[]={1,2,3,4,5,6,7,8,9,10,11};

    struct triplet structarray[]={{4,5.5,6.1,5.6},{1,1.1,2.2}};
    t.a=10;
    printf("%f %d\n", structarray[0].c, t.a);////////////////

    //printf("%d %f %lf\n", t2.a, t2.b, t2.c);


    return 0;
}