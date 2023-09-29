#include<iostream>
#include<time.h>
#include<algorithm>
using namespace std;

int comparisons;

int medianFinder(int l,int r,int *arr){
        for(int i=l;i<=r;i++){              //comparisons++;
            int temp=arr[l];
            for(int j=l-1;j>=l;j++){        //comparisons++;
                if(arr[j]>temp){            comparisons++;
                    arr[j+1]=arr[j];
                    arr[j]=temp;
                }
            }
        }
    return arr[(r+l)/2];
}

int selectgrp(int *arr,int l,int r,int k,int grp){
    int size=r-l+1;
    if(l==r and k==1)return arr[l];         //comparisons+=3;          
    int newsize=(size+grp-1)/grp;   
    int temp[newsize];
    {
        int l2,r2;
        for(int i=0;i<newsize;i++){         //comparisons++;            
            l2=l+grp*i;
            r2=l2+grp-1<=r?l2+grp-1:r;      comparisons++;      
            temp[i]=medianFinder(l2,r2,arr);
        }
    }
    int pivot=selectgrp(temp,0,newsize-1,(newsize+1)/2,grp);
    int PivotLeft=l-1,PivotPos,leftcount=0;
    for(int i=l;i<=r;i++){                  //comparisons++;          
        if(arr[i]<pivot){                                    
            int temp=arr[++PivotLeft];
            leftcount++;
            arr[PivotLeft]=arr[i];
            arr[i]=temp;
        }
    }
    for(int i=r;i>=l;i--){                  //comparisons++; 
        if(arr[i]==pivot){PivotPos=i;break;}comparisons++;  
    }
    {
        int temp=arr[PivotPos];
        arr[PivotPos]=arr[PivotLeft+1];
        arr[PivotLeft+1]=temp;
    }
                                            comparisons+=2;                                             
    if(leftcount==k-1)return arr[PivotLeft+1];
    else if(leftcount>k-1)return selectgrp(arr,l,PivotLeft,k,grp);
    else return selectgrp(arr,PivotLeft+2,r,k-leftcount-1,grp);
}

int FindLargestViaCustomBinary(int *arr,int l,int r,int END_INDEX){
    if(l==r)return arr[l];
    int mid=(l+r)/2;
    if(arr[mid]>arr[mid+1])return mid;
    else{
        if(arr[mid]>=arr[END_INDEX]){
            return FindLargestViaCustomBinary(arr,mid+1,r,END_INDEX);
        }
        else{
            return FindLargestViaCustomBinary(arr,l,mid,END_INDEX);
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    cout<<FindLargestViaCustomBinary(arr,0,n-1,n-1)<<endl;
    
    return 0;
}
