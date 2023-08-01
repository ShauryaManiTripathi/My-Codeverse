#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

int MINheight(int node){
    float c=log2f(node);
    int height = (int)c;
    return height;
}

int MAXheight(int node){
    if(node<2)return 0;
    int height=1;
    int a1=1;
    int a2=2;
    int sum=a1+a2+1;
    while(node>=sum){
        a1=a2;
        a2=sum;
        sum=a1+a2+1;
        height++;
    }
    return height;

}
int main(){
    int node;
    scanf("%d",&node);
    printf("Minheight :: %d\n",MINheight(node));
    printf("Maxheight :: %d\n",MAXheight(node));

}