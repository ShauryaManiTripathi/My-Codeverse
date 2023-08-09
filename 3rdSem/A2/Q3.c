#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

int TernarySearch(int *a,int key,int left,int right){
    if(left<=right){
        int mid1=left+1*(right-left)/3;
        int mid2=left+2*(right-left)/3;
        //printf("%d,%d\n",mid1,mid2);
        if(a[mid1]==key){
            return mid1;
        }
        if(a[mid1]>key){
            return TernarySearch(a,key,left,mid1);
        }
        if(a[mid2]==key){
            return mid2;
        }
        if(a[mid2]>key){
            return TernarySearch(a,key,mid1+1,mid2);
        }
        else {
            return TernarySearch(a,key,mid2+1,right);
        }
    }
    return -1;
}

int main(){
    int *a,n,key;
    puts("Enter sizeof(array)");
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    puts("Enter elements of array");
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    puts("enter the key to search");
    scanf("%d",&key);

    printf("Index:::::%d\n",TernarySearch(a,key,0,n-1));
    puts("if returned index is -1,implies the element was never found in the array");
    free(a);
    a=NULL;
}