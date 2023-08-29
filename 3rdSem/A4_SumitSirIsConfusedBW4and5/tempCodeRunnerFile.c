#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#pragma pack(1)

#define in(x) scanf("%d",&x);
#define out(x) printf("%d \t",x);

typedef struct pair{int x;int y;} pair;
typedef struct set{pair p1;pair p2;float distance;} set;

int compare1(const void *a,const void *b){
    return ((pair *)a)->x>=((pair *)b)->x?1:0;
}

int compare2(const void *a,const void *b){
    return ((pair *)a)->y>=((pair *)b)->y?1:0;
}

float distance(pair a,pair b){
     return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

set getclosestpair(pair *X,int l,int r,pair *Y,int size){

    printf("check (%d,%d)\n",l,r);
    if(r-l==1){
        set s={X[l],X[r],distance(X[l],X[r])};
        puts("end size 1\n");
        return s;
    }
    if(r>l){

        int mid=(l+r)/2;

        set cand1=getclosestpair(X,l,mid,Y,size);
        set cand2=getclosestpair(X,mid+1,r,Y,size);
