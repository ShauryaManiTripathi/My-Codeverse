//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
    private:
	int key;
    int endaddress(int arr[],int l,int r){
	    if(l<r){
	        int mid=(l+r)/2;
	        if(arr[mid]>key){
	            return endaddress(arr,l,mid-1);
	        }
	        if(arr[mid]==key){
                if(mid==r)return mid;
	            if(arr[mid+1]==key)return endaddress(arr,mid+1,r);
	            else return mid+1;
	        }
	        return endaddress(arr,mid+1,r);
	    }
        else{
        if(arr[l]==key)return l;
        else return -1;
        }
    }
    int initialaddress(int arr[],int l,int r){
        if(l<r){
	        int mid=(l+r)/2;
	        if(arr[mid]>key){
	            return initialaddress(arr,l,mid-1);
	        }
	        if(arr[mid]==key){
                if(mid==l)return mid;
	            if(arr[mid-1]==key)return initialaddress(arr,l,mid-1);
	            else return mid-1;
            }
	        return initialaddress(arr,mid+1,r);
        }
