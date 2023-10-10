#include<iostream>
using namespace std;



int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int key;
    cin>>key;

    int solutionfound=0;
    int ifound=0,jfound=n-1;

    for(int i=0;i<2*n;i++){
        if(ifound==n or jfound==-1)break;
        else
        if(a[ifound][jfound]==key){solutionfound=1;break;}
        else 
        if(a[ifound][jfound]>key)jfound--;
        else
        if(a[ifound][jfound]<key)ifound++;
    }
    if(solutionfound==1){
        cout<<"The coordinates is row:: "<<(ifound+1)<<" and column:: "<<(jfound+1);
    }
    else{
        cout<<"Element cant be found";
    }
    return 0;
}
