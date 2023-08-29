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
                        else return mid;
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
                        else return mid;
                    }
                    return initialaddress(arr,mid+1,r);
                }
                else{
                if(arr[l]==key)return l;
                else return -1;
                }
            }
    
    public:

            int count(int arr[], int n, int x) {
                key=x;
                int i=initialaddress(arr,0,n-1);
                int j=endaddress(arr,0,n-1);
                cout<<i<<" "<<j<<endl;
                if(i==-1 || j==-1)return 0;
                return j-i+1;
            }
	
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends