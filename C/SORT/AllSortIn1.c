#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

//implement merge sort on array
void mergee(int *arr,int left,int mid,int right){
    int n1 = mid-left+1;
    int n2 = right-mid;
    int *L = (int *)malloc(sizeof(int)*(n1+1));
    int *R = (int *)malloc(sizeof(int)*(n2+1));
    
    for(int i=0;i<n1;i++)
        L[i]=arr[left+i];
        L[n1]=INT_MAX;

    for(int j=0;j<n2;j++)
        R[j]=arr[mid+1+j];
        R[n2]=INT_MAX;

    int i=0,j=0;

    for(int k=0;k<n1+n2;k++){
        if(L[i]<=R[j]){
            arr[left+k]=L[i];
            i++;
        }
        else{
            arr[left+k]=R[j];
            j++;
        }
    }
    free(L);
    free(R);
}
//oo
void mergesort(int *arr, int low, int high){
    if(low<high){
        int mid = (low+high)/2;
        mergesort(arr, low, mid);
        mergesort(arr, mid+1, high);
        mergee(arr, low, mid, high);
    }
}
//inbuilt qsort function
int compare(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

//implement quick sort on array
void quicksort(int *arr,int left,int right){
    if(left>=right)return;
    int pivot=arr[right];
    int l=left;
    int r=right-1;
    while(l<r){
        while(arr[l]<=pivot && l<right)
        l++;
        while(arr[r]>pivot && r>=left)
        r--;
        if(l<r)swap(arr+l,arr+r);
    }
    if(r==left-1)
    {
        swap(arr+left,arr+right);
        quicksort(arr,left+1,right);
    }
    else if(l==right)
    {
        quicksort(arr,left,right-1);
    }
    else{
        if(arr[l]>arr[right])swap(arr+l,arr+right);
        quicksort(arr,left,r);
        quicksort(arr,l+1,right);
    }
}

// bubble sort
void bubblesort(int *arr,int n){
    for(int i=0;i<n;i++)
        for(int j=0;j<n-i-1;j++)
            if(arr[j]>arr[j+1])
                swap(arr+j,arr+j+1);
}

// insertion sort
void insertionsort(int *arr,int n){ 
    for(int i=0;i<n;i++)
        for(int j=i-1;j>=0;j--)    
            if(arr[j]>arr[j+1])
                swap(arr+j,arr+j+1);
            else break;
}

// selection sort
void selectionsort(int *arr,int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++)
            if(arr[j]<arr[i])
                swap(arr+i,arr+j);
    }
}





int main(){
    int a[]={1,2,3,3,2,1,1,2,3,3,2,1};
    int n = sizeof(a)/sizeof(a[0]);
    //mergesort(a,0,n-1);
    //qsort(a,n,sizeof(int),compare);
    //quicksort(a,0,n-1);
    //bubblesort(a,n);
    //insertionsort(a,n);
    //selectionsort(a,n);

    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
}


