#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << endl

void solve() {
    int n,k;
    cin>>n>>k;
    int bits[9];
    for(int i=0;i<9;i++){
        if(k&1)
            bits[i]=1;
        else
            bits[i]=0;
        k=k>>1;
    }
    for (int i = 0; i < 9; i++)
    {
        cout<<bits[i]<<" ";
    }
    for(int i=0;i<n;i++){
        int x=0;
        for(int j=0;j<9;j++){
            if(bits[j]==1){
                x=x|(1<<j);
            }
        }
        cout<<x<<" ";
    
    }
    
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("/home/dexter/Desktop/My-Codeverse/input", "r", stdin);
    freopen("/home/dexter/Desktop/My-Codeverse/output", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        // cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}