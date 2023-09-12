#include<iostream>
using namespace std;

int v1,v2,v3,v4;

int FiboBruteForce(int n){
    v1++;
    if(n<=1)return n;
    return FiboBruteForce(n-1)+FiboBruteForce(n-2);
}

int FiboV1(int n,int *arr){
    v2++;
    if(n<=1)return n;
    if(arr[n]!=-1)return arr[n];
    return arr[n]=FiboV1(n-1,arr)+FiboV1(n-2,arr);
    
}

int FiboV2(int curr,int n,int *arr){
    v3++;
    if(n<1)return n;
    if(curr==n)return arr[curr-1]+arr[curr-2];
    else{
        if(curr<=1)arr[curr]=curr;
        else arr[curr]=arr[curr-1]+arr[curr-2];
        return FiboV2(curr+1,n,arr);
    }
}

int FiboBEST(int n){
    int a=0,b=1;
    if(n<=1)return n;
    for(int i=0;i<n;i++){
        v4++;
        int temp=a+b;
        a=b;
        b=temp;
    }
    return a;
}

int main(){
    int n;

    cin>>n;

    int arr[n+1];

    for(int i=0;i<n+1;i++)arr[i]=-1;

    cout<<"Brute force output ---> "<<FiboBruteForce(n)<<"  Repitions --> "<<v1<<endl;

    cout<<"TopToBottom        ---> "<<FiboV1(n,arr)<<"  Repitions --> "<<v2<<endl;

    cout<<"BottomToTop        ---> "<<FiboV2(0,n,arr)<<"  Repitions --> "<<v3<<endl;

    cout<<"BestApproach       ---> "<<FiboBEST(n)<<"  Repitions --> "<<v4<<endl;


}