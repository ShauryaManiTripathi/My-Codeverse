#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << endl

void solve() {
    int n;
    cin >> n;
    char a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    //we need to find sum of modes of all substring
    int modes=(n*(n+1))/2;
    //use sliding window to find stings with modes=2
    unordered_map<int,int> freq;
    int diff=0;
    freq[0]=1;
    for(int i=0;i<n;i++){
        diff+=(a[i]=='1')?1:-1;
        //check if the key (diff ) exists
        if(freq.find(diff)!=freq.end()){
            modes+=freq[diff];
            freq[diff]++;
        }
        else{
            freq[diff]=1;
        }
    }
    cout<<modes<<endl;

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