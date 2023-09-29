#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int compare(pair<int,int> a,pair<int,int> b){
    return a.first>a.second;
}

int main(int argc, char const *argv[])
{
    vector<pair<int,int>> arr;
    int n;
    cin>>n;
    int a,b;
    for (int i = 0; i < n; i++)
    {
        cin>>a>>b;
        arr.push_back({a,b});
    }
    sort(arr.begin(),arr.end(),compare);
    for(int i=0;i<n;i++){
        cout<<arr[i].first<<" "<<arr[i].second<<"\t";
    }


    

    return 0;
}
