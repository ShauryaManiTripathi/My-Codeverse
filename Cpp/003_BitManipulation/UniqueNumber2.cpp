#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int findUniques(vector<int>&t){
    int s=0;
    for (int i = 0; i < t.size(); i++)
    {
        s=s^t[i];
    }
    int mask=1;
    
    
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
    findUniques(t);
    return 0;
}
