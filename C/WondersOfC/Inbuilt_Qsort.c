#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
int compare(const void* a,const void* b){
    return *(int*)a-*(int*)b;
}
int main(){
    int a[]={1,2,3,4,5,6,7,8,9,10,1,3,2,1,4,5,2,23,5,32,2};
    qsort(a,21,sizeof(int),compare);
    for(int i=0;i<21;i++)printf("%d ",a[i]);
}