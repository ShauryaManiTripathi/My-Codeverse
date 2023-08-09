#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

int SkewBinarySearch(int *a,int r,int base,int key,int num,int den){
    if(r>=0){
        int mid=num*r/den;
        if(a[mid]==key){
            return base+mid;
        }
        if(a[mid]>key){
            return SkewBinarySearch(a,mid-1,base,key,num,den);
        }
        else {
            base+=mid+1;
            return SkewBinarySearch(a+mid+1,r-mid-1,base,key,num,den);
        }
    }
    return -1;
}

int main(){
    int *a,n,key,num,den;
    puts("Enter sizeof(array)");
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    puts("Enter elements of array");
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    puts("enter the key,numerator and denominator seperated by space and press enter");
    scanf("%d %d %d",&key,&num,&den);

    printf("Index:::%d\n",SkewBinarySearch(a,n,0,key,num,den));
    puts("if returned index is -1,implies the element was never found in the array");
    free(a);
    a=NULL;
}