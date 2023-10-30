#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	int n;
	cin>>n;
	long long int arr[n];
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	long long int cm[n];
	long long int maxx=arr[0];
	for(int i=n-1;i>=0;i--){
	    if(i==n-1){
            cm[i]=arr[i];
        }
        else{
            if(arr[i]>cm[i+1]){
                cm[i]=arr[i];
            }
            else{
                cm[i]=cm[i+1];
            }
        }
	}
    for(int i=0;i<n;i++){
        cout<<cm[i]<<" ";
    }   
    cout<<endl;
    //
    int sum=arr[0];
    for(int i=1;i<n-1;i++){
        arr[i]= max(arr[i],min(maxx,cm[i+1]));
        if(arr[i]>=maxx){
            maxx=arr[i];
        }
        sum+=arr[i];
    }
    sum+=arr[n-1];
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }   
    cout<<endl;
    cout<<sum<<endl;
	return 0;
}
