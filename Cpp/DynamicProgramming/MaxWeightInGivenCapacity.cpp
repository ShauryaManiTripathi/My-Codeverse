#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n, capacity;
    cin>>n>>capacity;
    int weights[n];
    for(int i=0; i<n; i++)
        cin>>weights[i];
    int DPtable[n+1][capacity+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<capacity+1;j++){
            if(i==0 || j==0)
                DPtable[i][j] = 0;
            else if(weights[i-1] <= j)
                DPtable[i][j] = max( weights[i-1] + DPtable[i-1][j-weights[i-1]], DPtable[i-1][j]);
            else
                DPtable[i][j] = DPtable[i-1][j];
        }
    }
    for(int i=0;i<n+1;i++){
        for(int j=0;j<capacity+1;j++){
            cout<<DPtable[i][j]<<"\t ";
        }
        cout<<endl;
    }
    return 0;
}
