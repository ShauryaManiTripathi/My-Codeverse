#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int s=2*n;
        int a[s];
        for(int i=0;i<s;i++){
            cin>>a[i];
        }
        int p=0,count=0;
        while(n!=s){
            if(a[p]<=a[n]){
                p++;n++;
            }
            else{
                n++;count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
