#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#pragma pack(1)

#define in(x) scanf("%d",&x);
#define out(x) printf("%4d \t",x);

typedef struct pair{int x;int y;} pair;
typedef struct set{pair p1;pair p2;float distance;} set;

int compare1(void *a,void *b){
    return ((pair *)a)->x>=((pair *)b)->x?1:0;
}

int compare2(const void *a,const void *b){
    return ((pair *)a)->y>=((pair *)b)->y?1:0;
}

float distance(pair a,pair b){
     return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

set getclosestpair(pair *X,int l,int r,pair *Y,int size){

    //printf("check (%d,%d)\n",l,r);
    if(r-l==1){
        set s={X[l],X[r],distance(X[l],X[r])};
        //puts("end size 1\n");
        return s;
    }
    if(r>l){

        int mid=(l+r)/2;

        set cand1=getclosestpair(X,l,mid,Y,size);
        set cand2=getclosestpair(X,mid+1,r,Y,size);

        //printf("PassGate 1 (%d,%d)\n",l,r);

        set minset=cand1.distance>=cand2.distance?cand2:cand1;

        //printf("PassGate 2 (%d,%d) and mindistance=%f\n",l,r,minset.distance);

                                                                
                                                                    int n=0;
                                                                    for(int i=0;i<size;i++){
                                                                        if((float)(X[mid].x-minset.distance)<=(float)Y[i].x && (float)Y[i].x<=(float)(X[mid].x+minset.distance)){
                                                                            n++;
                                                                        }
                                                                    }
                                                                    //printf("PassGate 3 (%d,%d) and Stripcount=%d\n",l,r,n);
                                                                    pair newYset[n];
                                                                    
                                                                        int j=0;
                                                                        for(int i=0;i<size;i++){
                                                                            if((float)(X[mid].x-minset.distance)<=(float)Y[i].x && (float)Y[i].x<=(float)(X[mid].x+minset.distance)){
                                                                                newYset[j]=Y[i];
                                                                                j++;
                                                                                //printf("newYset check %d %d\n",newYset[j-1].x,newYset[j-1].y);
                                                                            }
                                                                        }
                                                                    


    set minpartition={{0,0},{0,0},(float)INT_MAX};
    //printf("Checking minpartition %d %d %d %d %f\n",minpartition.p1.x,minpartition.p1.y,minpartition.p2.x,minpartition.p2.y,minpartition.distance);
    for(int i=0;i<n;i++){
        //puts("loopcheck\n");
        for(int j=i+1;j<n && j<i+8;j++){
            if(minpartition.distance>=distance(newYset[i],newYset[j])){
                minpartition.p1=newYset[i];
                minpartition.p2=newYset[j];
                minpartition.distance=distance(newYset[i],newYset[j]);
            }
        }
    }
    //printf("Checking minpartition %d %d %d %d %f\n",minpartition.p1.x,minpartition.p1.y,minpartition.p2.x,minpartition.p2.y,minpartition.distance);
    set finalMIN= minpartition.distance<=minset.distance?minpartition:minset;
    //printf("Checking finalMIN %d %d %d %d %f\n",finalMIN.p1.x,finalMIN.p1.y,finalMIN.p2.x,finalMIN.p2.y,finalMIN.distance);
    return finalMIN;
    }
    else 
    {
        set s={{0,0},{0,0},(float)INT_MAX};
        //puts("End size 0\n");
        return s;
    }
}

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
    pair *X=(pair *)a;
    for(int i=0;i<size;i++){
        out(X[l+i].x);
        out(X[l+i].y);
    }
    puts("");

    //free(temp);

}

void mergesort_universal(void *a,int l,int r,int BYTES,comparator compare){
    if(l>=r)return;
    int mid=(l+r)/2;
    mergesort_universal(a,l,mid,BYTES,compare);
    mergesort_universal(a,mid+1,r,BYTES,compare);
    o2n(l,r);
    merge_universal(a,l,mid,r,BYTES,compare);
}



int main(){
    int n;
    //puts("Enter the number of points to give");
    in(n);
    pair* X=malloc(n*sizeof(pair));
    pair* Y=malloc(n*sizeof(pair));
    //puts("Enter the coordinates seperated by space , one point per line");
    for(int i=0;i<n;i++){
        in(X[i].x);
        in(X[i].y);
        Y[i].x=X[i].x;
        Y[i].y=X[i].y;
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
    // puts("\n");
    // for(int i=0;i<n;i++){
    //     out(Y[i].x);
    //     out(Y[i].y);
    // }
    // puts("\n");

    // float aa=distance(X[0],X[2]);
    // printf("%f %d\n",aa,n);
    //  set ans=getclosestpair(X,0,n-1,Y,n);
    //  printf("%d,%d -- %d,%d -- %f",ans.p1.x,ans.p1.y,ans.p2.x,ans.p2.y,ans.distance);
     
}