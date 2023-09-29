#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0;i<n+1;i++){
        if(i>1)arr[i]=arr[i-1]*i;
        else arr[i]=i;
    }
    for(int i=0;i<n+1;i++){
        cout<<arr[i]<<"\t";
    }

    return 0;
}
