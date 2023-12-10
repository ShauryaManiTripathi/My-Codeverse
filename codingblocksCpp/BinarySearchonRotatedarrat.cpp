#include<iostream>
using namespace std;

int rotBinarySearch(int *a,int l,int r,int key){
    if(l>r){
        return -1;
    } 
    else{
        int mid=(l+r)/2;
        if(key==a[mid])return mid;
        if(key<a[mid]){
            if(a[mid]<a[0])return rotBinarySearch(a,l,mid-1,key);
            else return rotBinarySearch(a,mid+1,r,key);
        }
        else{
            if(a[mid]);
        }

    }
}
int main(int argc, char const *argv[])
{
    int n;
    std::cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    int key;
    cin>>key;
          
    return 0;
}
