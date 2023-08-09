#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

void merge2(int *a,int l,int mid,int r){
    int n1=mid-l+2;
    int n2=r-mid+1;
    int a1[n1];
    int a2[n2];
    for(int i=0;i<n1-1;i++){
    a1[i]=a[l+i];
    }
    a1[n1-1]=__INT32_MAX__;
    for(int i=0;i<n2-1;i++){
    a2[i]=a[mid+1+i];
    }
    a2[n2-1]=__INT32_MAX__;
    int ii=0,jj=0;
    for(int i=0;i<n1+n2-2;i++){
        if(a1[ii]<a2[jj]){
            a[l+i]=a[ii];
            ii++;
        }
        else{
            a[l+i]=a[jj];
            jj++;
        }
    }

}

void merge4(int *a,int l,int *mid,int midsize,int r){
    int n1=mid[0]-l+2;
    int n2=mid[1]-mid[0]+1;      
    int n3=mid[2]-mid[1]+1;
    int n4=r-mid[2]+1;
    int a1[n1],a2[n2],a3[n3],a4[n4];
    for(int i=0;i<n1-1;i++){
        a1[i]=a[l+i];
    }
    a1[n1-1]=__INT32_MAX__;
    for(int i=0;i<n2-1;i++){
        a2[i]=a[mid[0]+i];
    }
    a2[n2-1]=__INT32_MAX__;
    for(int i=0;i<n3-1;i++){
        a3[i]=a[mid[1]+i];
    }
    a3[n3-1]=__INT32_MAX__;
    for(int i=0;i<n4-1;i++){
        a4[i]=a[mid[2]+i];
    }
    a4[n4-1]=__INT32_MAX__;

    int pointer[4]={0,0,0,0};
    int *arrays[4]={a1,a2,a3,a4};

    for(int j=0;j<n1+n2+n3+n4-4;j++){
        int max=0;
        for(int i=1;i<4;i++){
            if(arrays[i][pointer[i]]<arrays[max][pointer[max]]){
                max=i;
            }
        }
        a[j]=arrays[max][pointer[max]];
        pointer[max]++;
    }

}

void mergesort2(int *a,int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        mergesort2(a,l,mid);
        mergesort2(a,mid+1,r);
        merge2(a,l,mid,r);
    }
}

void mergesort4(int *a,int l,int r){
    if(l<r){
        int mid[3]={(3*l+r)/4,(2*l+2*r)/4,(1*l+3*r)/4};
        mergesort4(a,l,mid[0]);
        mergesort4(a,mid[0]+1,mid[1]);
        mergesort4(a,mid[1]+1,mid[2]);
        mergesort4(a,mid[2]+1,r);
        //merge4(a,l,mid,3,r);
    }
}



int main(){
    int *a,n;
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    printf("mellow:::%d",printf("hello::%d\n",scanf("%d",&n)));
    //mergesort2(a,0,n-1);
    
}