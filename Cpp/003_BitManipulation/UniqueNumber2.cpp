#include<iostream>
#include<algorithm>
#include<vector>
#include<bitset>
using namespace std;


//findTheUnique1 is easy
void findTheUnique2(vector<int>&t){//just segregate both numbers
    int s=0;
    for (int i = 0; i < t.size(); i++)
    {
        s=s^t[i];
    }
    int mask=1;
    while(1){
        if(s&mask)break;
        else mask=mask<<1;
    }
    bitset<32> a1(s);
    bitset<32> a2(mask);
    cout<<" s== "<<a1<<endl<<" m== "<<a2<<endl;
    int val1=0,val2=0;
    for (int i = 0; i < t.size(); i++)
    {
        if(t[i]&mask){
            val1=val1^t[i];
        }
        else{
            val2=val2^t[i];
        }
    }
    cout<<val1<<" "<<val2<<endl;
}

int main(int argc, char const *argv[])
{
    vector<int> t;
    cout<<"Enter until -1 appears"<<endl;
    while(1){
        int temp;
        cin>>temp;
        if(temp==-1)break;
        t.push_back(temp);
    }
    for (int i = 0; i < t.size(); i++)
    {
        cout<<t[i]<<" ";
    }
    cout<<endl;
    bitset<32> a1(111);
    bitset<32> a2(7);
    cout<<a1<<endl<<a2<<endl;
    findTheUnique2(t);
    t.clear();
    return 0;
}