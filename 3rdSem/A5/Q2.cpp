#include<iostream>
#include<time.h>
#include<algorithm>
using namespace std;

int comparisons;

int medianFinder(int l,int r,int *arr){
        for(int i=l;i<=r;i++){              comparisons++;
            int temp=arr[l];
            for(int j=l-1;j>=l;j++){        comparisons++;
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
    if(l==r and k==1)return arr[l];         comparisons++;comparisons++;          
    int newsize=(size+grp-1)/grp;   
    int temp[newsize];
    {
        int l2,r2;
        for(int i=0;i<newsize;i++){         comparisons++;            
            l2=l+grp*i;
            r2=l2+grp-1<=r?l2+grp-1:r;      comparisons++;      
            temp[i]=medianFinder(l2,r2,arr);
        }
    }
    int pivot=selectgrp(temp,0,newsize-1,(newsize+1)/2,grp);
    int PivotLeft=l-1,PivotPos,leftcount=0;
    for(int i=l;i<=r;i++){                  comparisons++;          
        if(arr[i]<pivot){                                    
            int temp=arr[++PivotLeft];
            leftcount++;
            arr[PivotLeft]=arr[i];
            arr[i]=temp;
        }
    }
    for(int i=r;i>=l;i--){                  comparisons++; 
        if(arr[i]==pivot){PivotPos=i;break;}comparisons++;  
    }
    {
        int temp=arr[PivotPos];
        arr[PivotPos]=arr[PivotLeft+1];
        arr[PivotLeft+1]=temp;
    }
                                            comparisons++;                                             
    if(leftcount==k-1)return arr[PivotLeft+1];
    else if(leftcount>k-1)return selectgrp(arr,l,PivotLeft,k,grp);
    else return selectgrp(arr,PivotLeft+2,r,k-leftcount-1,grp);
}

int main(){
    int n;
    cin>>n;
    n=10000;
    int arr1[n],arr2[n],arr3[n],arr4[n];
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        cin>>arr1[i];
        arr1[i]=rand()%1000000+98435;
        arr4[i]=arr3[i]=arr2[i]=arr1[i];
    }
    cout<<endl<<"Note:- The comparisons are those added by user,internal comparisons are not included!"<<endl;
    cout<<selectgrp(arr1,0,n-1,6*n/10,3)<<", comparisons required -----> "<<comparisons<<"\tfor group size =3"<<endl;
    comparisons=0;
    cout<<selectgrp(arr2,0,n-1,6*n/10,5)<<", comparisons required -----> "<<comparisons<<"\tfor group size =5"<<endl;
    comparisons=0;
    cout<<selectgrp(arr3,0,n-1,6*n/10,7)<<", comparisons required -----> "<<comparisons<<"\tfor group size =7"<<endl;
    comparisons=0;
    cout<<selectgrp(arr4,0,n-1,6*n/10,9)<<", comparisons required -----> "<<comparisons<<"\tfor group size =9"<<endl;
    sort(arr1,arr1+n);
    cout<<arr1[6*n/10-1];

}