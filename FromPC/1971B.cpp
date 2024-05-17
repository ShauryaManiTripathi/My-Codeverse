#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << endl

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    if (s.length() <= 1)
    {
        cout << "NO" << endl;
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] != s[i + 1])
        {
            cout << "YES" << endl;
            char c = s[i + 1];
            s[i + 1] = s[i];
            s[i] = c;
            cout << s << endl;
            return;
        }
    }
    cout << "NO" << endl;
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("D:/test/My-Codeverse/input", "r", stdin);
    freopen("D:/test/My-Codeverse/output", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}