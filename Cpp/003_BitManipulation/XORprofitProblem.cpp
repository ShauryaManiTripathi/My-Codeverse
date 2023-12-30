#include<bits/stdc++.h>
using namespace std;

int maxXORinArray(int a,int b){
    int max=__INT_MAX__+1;
    for(int i=a;i<=b;i++){
        for(int j=i+1;j<=b;j++){
            if(max<(a^b))max=a^b;
        }
    }
    return max;
}

int main(int argc, char const *argv[])
{
    int a,b;
    cin>>a>>b;
    cout<<maxXORinArray(a,b);

    return 0;
}
