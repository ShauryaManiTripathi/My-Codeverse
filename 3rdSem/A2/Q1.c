#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

void check(){
    int *a,n;
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    if(a[0]>a[n-1]){
        printf("Maximum=%d,Minimum=%d",a[0],a[n-1]);
    }
    else{
        printf("Maximum=%d,Minimum=%d",a[n-1],a[0]);
    }
    free(a);
    a=NULL;
}

int main(){
    check();
}