#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#pragma pack(1)

#define i(x) scanf("%d",&x);
#define i2(x,y) scanf("%d %d",&x,&y);
#define o1(x) printf("%d",x);
#define o2(x,y) printf("%d - %d |",x,y);
#define o1n(x) printf("%d\n",x);
#define o2n(x,y) printf("%d - %d\n",x,y);

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
        o2(ptrs[0],ptrs[1]);
        ptrs[idx]++;
    }
    puts("");
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
    
}

