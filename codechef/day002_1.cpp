#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << endl

void solve() {
    int n;
    cin>>n;
    int initialODDindex=-1,lastODDindex=-1,totalODD=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x%2==1){
            totalODD++;
            if(initialODDindex==-1){
                initialODDindex=i;
            }
            lastODDindex=i;
        }
    }
    if(totalODD%2==0){
        cout<<n<<endl;
    }
    else{
        cout<<max(n-initialODDindex-1,lastODDindex)<<endl;
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
        //cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}