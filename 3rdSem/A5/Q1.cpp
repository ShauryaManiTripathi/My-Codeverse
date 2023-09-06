#include<iostream>
using namespace std;

int v1,v2,v3,v4;

int FiboBruteForce(int n){
    v1++;
    if(n<=2)return n-1;
    return FiboBruteForce(n-1)+FiboBruteForce(n-2);
}

int FiboV1(int n,int *arr){
    v2++;
    if(n<=2)return n-1;
    int a,b;   

    if(arr[n-2]!=-1)a=arr[n-2];
    else {a=FiboV1(n-1,arr);arr[n-2]=a;}

    if(arr[n-3]!=-1)b=arr[n-3];
    else {b=FiboV1(n-2,arr);arr[n-3]=b;}

    return arr[n-1]=a+b;
    
}

int FiboV2(int curr,int n,int *arr){
    v3++;
    if(curr!=n){
        if(curr<=2)arr[curr-1]=curr-1;
        else arr[curr-1]=arr[curr-2]+arr[curr-3];
        return FiboV2(curr+1,n,arr);
    }
    else 
    return arr[n-1]=arr[n-2]+arr[n-3];
}

int FiboBEST(int n){
    int a=0,b=1;
    if(n<=2)return n-1;
    for(int i=1;i<n;i++){
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

    int arr[n];

    for(int i=0;i<n;i++)arr[i]=-1;

    cout<<"Brute force output ---> "<<FiboBruteForce(n)<<"  Repitions --> "<<v1<<endl;

    cout<<"TopToBottom        ---> "<<FiboV1(n,arr)<<"  Repitions --> "<<v2<<endl;

    cout<<"BottomToTop        ---> "<<FiboV2(1,n,arr)<<"  Repitions --> "<<v3<<endl;

    cout<<"BestApproach       ---> "<<FiboBEST(n)<<"  Repitions --> "<<v4<<endl;


}