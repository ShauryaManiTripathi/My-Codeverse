#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << endl

void solve() {
    char a[4];
    for(int i=0;i<4;i++){
        cin>>a[i];
    }
    int hori=1,vert=1;
    if(a[0]=='1'){
        hori+=10;
    }
    if(a[1]=='1'){
        hori+=10;
    }
    if(a[2]=='1'){
        vert+=10;
    }
    if(a[3]=='1'){
        vert+=10;
    }
    cout<<(hori*vert)<<endl;
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