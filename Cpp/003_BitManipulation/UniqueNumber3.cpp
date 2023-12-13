#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void uniqueNumber3(vector<int> &t)
{
    int bitts[31]={0};
    for(int j=0;j<31;j++){
        int mask=1<<j;
        for (int i = 0; i < t.size(); i++){
            if(mask&t[i])bitts[30-j]++;
        }
    }
    int temp=1;
    int finals=0;
    for(int i=30;i>=0;i--){
        bitts[i]=bitts[i]%3;
        if(bitts[i])finals+=temp;
        temp*=2;
    }
    cout<<finals<<endl;
}

int main(int argc, char const *argv[])
{
    vector<int> t;
    while (1)
    {
        int temp;
        cin >> temp;
        if (temp < 0)
            break;
            t.push_back(temp);
        
    }
    uniqueNumber3(t);
    return 0;
}
