#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define debug(x) cout << #x << " = " << x << endl

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if(n==1){
        cout<<1<<endl;
        return;
    }
    int **dp;
    dp = new int *[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        int j = i;
        int k = 0;
        int caught = 1;
        while (j < n)
        {
            if (j == k)
            {
                dp[k][j] = a[j];
            }
            else
            {
                dp[k][j] = dp[k][j - 1] | a[j];
            }
            if (k != 0)
            {
                if (dp[k][j] != dp[k - 1][j - 1])
                {
                    caught = 0;
                }
            }
            k++;
            j++;
        }
        if (caught)
        {
            cout << (i + 1) << endl;
            for (int i = 0; i < n; i++)
            {
                delete[] dp[i];
            }
            delete[] dp;
            return;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("/home/dexter/Desktop/My-Codeverse/input", "r", stdin);
    freopen("/home/dexter/Desktop/My-Codeverse/output", "w", stdout);
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