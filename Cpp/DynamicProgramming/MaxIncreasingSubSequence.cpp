#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main(int argc, char const *argv[])
{
    string a,b;
    cin>>a>>b;
    int n = a.length();
    int m = b.length();
    int arr[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 or j==0)arr[i][j]=0;
            else
            if(a.at(i-1)==b.at(j-1)){
                arr[i][j]=arr[i-1][j-1]+1;
            }
            else arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
}