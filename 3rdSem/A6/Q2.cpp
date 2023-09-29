#include<iostream>
#include<vector>
#include<string>
using namespace std;


int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    long long int arr[n+1][n+1];
    //rows=no of positons
    //colums=number of players
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(j>=i){
            if(i==0 or j==0)arr[i][j]=0;
            else
            if(i==1)arr[i][j]=1;
            else
            if(j==1)arr[i][j]=i;
            else
            arr[i][j]=i*arr[i-1][j-1]+arr[i-1][j];
            }
            else arr[i][j]=0;
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
        cout<<arr[i][j]<<"\t";
    }
    cout<<endl;
    }
    return 0;
}
