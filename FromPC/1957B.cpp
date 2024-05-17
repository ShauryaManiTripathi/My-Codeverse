#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << endl

void solve() {
    int n,k;
    cin>>n>>k;
    int temp=k;
    int bits[32];
    int msb=-1,count=0;
    if(n==1){
        cout<<k<<endl;return;}
    for(int i=0;i<32;i++){
        if(k&1){
            bits[0]=1;
            msb=i;
            count++;
        }
        else{
            bits[0]=0;
        }
        k=k>>1;
    }

    if(count==msb+1){
        cout<<temp<<" ";
        for(int i=0;i<n-1;i++){
            cout<<"0"<<" ";
        }
        cout<<endl;
    }
    else{
        int x=pow(2,msb)-1;
        cout<<x<<" ";
        cout<<(temp-x)<<" ";
        for(int i=0;i<n-2;i++){
            cout<<"0"<<" ";
        }
        cout<<endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("D:/test/My-Codeverse/input", "r", stdin);
    freopen("D:/test/My-Codeverse/output", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        // cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}