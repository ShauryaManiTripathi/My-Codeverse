#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<limits.h>
#include<math.h>
// find missing number between 1 to n+1 where n is size of array containing 
// 1 to n+1 nums with one missing in ascending order
int find_Missing_Number(int *a,int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        if(a[mid]==mid+1)return find_Missing_Number(a,mid+1,r);
        else return find_Missing_Number(a,l,mid);
    }
    else{
        if(a[l]==l+1)return l+2;
        else return l+1;
    }

}

int main(){
    int a[10]={2,3,4,5,6,7,8,9,10,11};
    printf("%d\n",find_Missing_Number(a,0,9));
}