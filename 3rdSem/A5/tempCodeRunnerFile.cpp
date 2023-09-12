    if(arr[n-1]!=-1)a=arr[n-1];
    else {a=FiboV1(n-1,arr);arr[n-1]=a;}

    if(arr[n-2]!=-1)b=arr[n-3];
    else {b=FiboV1(n-2,arr);arr[n-2]=b;}

    return arr[n]=a+b;
    
}

int FiboV2(int curr,int n,int *arr){
    v3++;
    if(n<=1)return n;
    else{
        if(curr<=1)arr[curr]=curr;
        else 
        if(arr[curr]==-1)
        arr[curr]=arr[curr-1]+arr[curr-2];
        if(curr==n)return arr[curr];
        else return FiboV2(curr+1,n,arr);
    }
    

}

int FiboBEST(int n){
    int a=0,b=1;
    if(n<=1)return n;
    for(int i=0;i<n;i++){
        v4++;