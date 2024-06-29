#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << endl
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>                                                       
#define vpii vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define pb push_back



void solve() {
    int a,b;
    cin>>a>>b;
    int mostdraws=-max(-a,-b);
    int t=0;
    while(t<=mostdraws){
        if((a-t)%3==0 && (b-t)%3==0){
            cout<<t<<endl;
            return;
        }
        t++;
    }
    cout<<0<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    //freopen("/home/dexter/Desktop/My-Codeverse/input", "r", stdin);
    //freopen("/home/dexter/Desktop/My-Codeverse/output", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        // cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}