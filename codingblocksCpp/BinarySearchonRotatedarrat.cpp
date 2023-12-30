#include<iostream>
#include<string>
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

int maxScore(string s) {
        int n=s.length();
        int a[s.length()]={0};
        int b[s.length()]={0};
        if(s.at(0)=='0')a[0]=1;
        if(s.at(n-1)=='1')b[n-1]=1;
        for(int i=1;i<n;i++){
            (s.at(i)=='0')?(a[i]+=a[i-1]+1):(a[i]+=a[i-1]);
            (s.at(n-1-i)=='1')?(b[n-1-i]+=b[n-i]+1):(b[n-1-i]+=b[n-i]);
        }
        int max=__INT_MAX__+1;
        for(int i=1;i<n;i++){
            if(max<a[i-1]+b[i])max=a[i-1]+b[i];
        }
        cout<<max<<endl;
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
    cout<<endl;
    string s="011101";
    maxScore(s);
          
    return 0;
}
