#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<limits.h>
#include<math.h>

int Max(int a,int b,int c,int d){
    int largest=a>b?a:b;
    largest=largest>c?largest:c;
    largest=largest>d?largest:d;
    return largest;
}
int findMaxProd(int *a,int size){
    if(size==1){
        return a[0];
    }
    if(size>1){
        int size1=size/2;
        int cand1=findMaxProd(a,size1);
        int cand2=findMaxProd(a+size1,size-size1);
        //////////////////
        int max1=a[size1-1],min1=a[size1-1],cur1=1;
        for(int i=size1-1;i>=0;i--){
            cur1*=a[i];
            if(cur1>max1)max1=cur1;
            if(cur1<min1)min1=cur1;
        }
        ///////////////////
        int max2=a[size1],min2=a[size1],cur2=1;
        for(int i=size1;i<size;i++){
            cur2*=a[i];
            if(cur2>max2)max2=cur2;
            if(cur2<min2)min2=cur2;
        }
        ///////////////////
        return Max(cand1,cand2,max1*max2,min1*min2);
    }
}
int main(){
int a[10]={-100,-100,0,0,100000,-1,0,0,10,11};
    printf("%d",findMaxProd(a,10));
}