#include <iostream>
#include <map>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        map<int,priority_queue<int>> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]>>2].push(-a[i]);        
        }
        for(int i=0;i<n;i++){
            cout<< -mp[a[i]>>2].top()<<" ";
            mp[a[i]>>2].pop();
        }
        cout<<endl;
        



    }
    return 0;
}
