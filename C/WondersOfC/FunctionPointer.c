#include<stdio.h>
#include<stdlib.h>
typedef int (*f)(int a,int b);
int add(int a, int b){
return a+b;
}
int sub(int a, int b){
return a-b;
}
f fp(f test){
return test==add?sub:add;
}
//add=pointer of add function
//add(1,3)=proper function call
int main(){
    int (*g)(int a,int b)=sub;
    printf("%d",fp(sub)(1,2));
}

