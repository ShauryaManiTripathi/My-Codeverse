#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#pragma pack(1)

#define in(x) scanf("%d",&x);
#define out(x) printf("%4d \t",x);
#define i(x) scanf("%d",&x);
#define i2(x,y) scanf("%d %d",&x,&y);
#define o1(x) printf("%d",x);
#define o2(x,y) printf("%d - %d |",x,y);
#define o1n(x) printf("%d\n",x);
#define o2n(x,y) printf("%d - %d\n",x,y);

typedef struct pair{int x;int y;} pair;

typedef int (*comparator)(void *a,void *b);

void swapBYTE(char *a,char *b){
    char temp=*b;
    *b=*a;
    *a=temp;
}

void swapMEM(void *a,void *b,int BYTES){
    for(int i=0;i<BYTES;i++){
        swapBYTE((char *)a+i,(char *)b+i);
    }
}

void setMEM(void *des,void *source,int BYTES){
    for(int i=0;i<BYTES;i++){
        *((char *)des+i)=*((char *)source+i);
    }
}

int hellow(void *a,void *b){
    return 1;
}

int compare1(void *a,void *b){
    return ((pair *)a)->x<=((pair *)b)->x?0:1;
}

void merge_universal(void *a,int l,int mid,int r,int BYTES,comparator compare){
    int size=r-l+1;
    int ptrs[]={l,mid+1};
    int MAXvalptrs[]={mid,r};
    //void *temp=malloc(size*BYTES);
    char temp[size*BYTES];
    for(int i=0;i<=size;i++){
        int idx=compare((char *)a+ptrs[0]*BYTES,(char *)a+ptrs[1]*BYTES)?1:0;
        if(ptrs[0]>MAXvalptrs[0])idx=1;
        if(ptrs[1]>MAXvalptrs[1])idx=0;
        setMEM((char *)temp+i*BYTES,(char *)a+ptrs[idx]*BYTES,BYTES);
        //o2(ptrs[0],ptrs[1]);
        ptrs[idx]++;
    }
    //puts("");
    for(int i=0;i<size;i++){
        setMEM((char *)a+(l+i)*BYTES,(char *)temp+i*BYTES,BYTES);
    }

    //free(temp);

}

void mergesort_universal(void *a,int l,int r,int BYTES,comparator compare){
    if(l>=r)return;
    int mid=(l+r)/2;
    mergesort_universal(a,l,mid,BYTES,compare);
    mergesort_universal(a,mid+1,r,BYTES,compare);
    //o2n(l,r);
    merge_universal(a,l,mid,r,BYTES,compare);
}

int main(){
  int n;
    //puts("Enter the number of points to give");
    in(n);
    pair* X=malloc(n*sizeof(pair));
    //pair* Y=malloc(n*sizeof(pair));
    //puts("Enter the coordinates seperated by space , one point per line");
    for(int i=0;i<n;i++){
        in(X[i].x);
        in(X[i].y);
        //Y[i].x=X[i].x;
        //Y[i].y=X[i].y;
    }

    for(int i=0;i<n;i++){
        out(X[i].x);
        out(X[i].y);
    }
    puts("\n");

    //qsort(X,n,sizeof(pair),compare1);
    mergesort_universal(X,0,n-1,sizeof(pair),compare1);
    // qsort(Y,n,sizeof(pair),compare2);
    
    for(int i=0;i<n;i++){
        out(X[i].x);
        out(X[i].y);
    }  
}

