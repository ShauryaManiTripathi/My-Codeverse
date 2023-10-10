#include<iostream>
using namespace std;



int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int key;
    cin>>key;
/////////////////////////////////
    int DP[n][n];
    //DP portion , runs in O(n sqred)
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i<j){
                if((a[j]-a[i])>=key)DP[i][j]=1;
                else DP[i][j]=0;
            }
            else DP[i][j]=0;
        }
    }
    cout<<"Raw matrix"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           cout<<DP[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
    int max=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(i==0)continue;
            if(DP[i][j]==1){
                int largest=DP[i-1][j-1];
            largest=largest>DP[i-1][j]?largest:DP[i-1][j];
                DP[i][j]=1+largest;
            }
            else{
                int largest=DP[i-1][j-1];
            largest=largest>DP[i-1][j]?largest:DP[i-1][j];
            DP[i][j]=largest;
            }
            if(max<DP[i][j])max=DP[i][j];
        }
    }
    cout<<"Dynamic feeded matrix"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           cout<<DP[i][j]<<"\t";
        }
        cout<<endl;
    }
    if(max)cout<<"The size of long subseq is "<<max;
    else cout<<"The longest subseq is not found";


////////////////////////////////
    
    return 0;
}
