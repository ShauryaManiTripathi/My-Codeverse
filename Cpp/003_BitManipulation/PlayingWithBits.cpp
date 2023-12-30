#include <iostream>
#include <algorithm>
using namespace std;

int countSetBits(int a, int b)
{
    if (a > b)
        swap(a, b);
    int count = 0;
    for (int i = a; i <= b; i++)
    {
        int mask = 1, setBits = 0;
        for (int j = 0; j < 32; j++)
        {
            if (i & mask)
                setBits++;
            mask = mask << 1;
        }
        count += setBits;
    }
    return count;
}
int main()
{
    int count=0,Q;
    cin>>Q;
    int a,b;
    while(Q--){
        cin>>a>>b;
        cout<<countSetBits(a,b)<<endl;
    }
    return 0;
}