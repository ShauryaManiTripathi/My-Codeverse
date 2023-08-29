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

        printf("PassGate 1 (%d,%d)\n",l,r);

        set minset=cand1.distance>=cand2.distance?cand2:cand1;

        printf("PassGate 2 (%d,%d) and mindistance=%f\n",l,r,minset.distance);

                                                                
                                                                    int n=0;
                                                                    for(int i=0;i<size;i++){
                                                                        if((float)(X[mid].x-minset.distance)<=(float)Y[i].x && (float)Y[i].x<=(float)(X[mid].x+minset.distance)){
                                                                            n++;
                                                                        }
                                                                    }
                                                                    printf("PassGate 3 (%d,%d) and Stripcount=%d\n",l,r,n);
                                                                    pair newYset[n];
                                                                    
                                                                        int j=0;
                                                                        for(int i=0;i<size;i++){
                                                                            if((float)(X[mid].x-minset.distance)<=(float)Y[i].x && (float)Y[i].x<=(float)(X[mid].x+minset.distance)){
                                                                                newYset[j]=Y[i];
                                                                                j++;
                                                                                printf("newYset check %d %d\n",newYset[j-1].x,newYset[j-1].y);
                                                                            }
                                                                        }
                                                                    


    set minpartition={{0,0},{0,0},(float)INT_MAX};
    printf("Checking minpartition %d %d %d %d %f\n",minpartition.p1.x,minpartition.p1.y,minpartition.p2.x,minpartition.p2.y,minpartition.distance);
    for(int i=0;i<n;i++){
        puts("loopcheck\n");
        for(int j=i+1;j<n && j<i+8;j++){
            if(minpartition.distance>=distance(newYset[i],newYset[j])){
                minpartition.p1=newYset[i];
                minpartition.p2=newYset[j];
                minpartition.distance=distance(newYset[i],newYset[j]);
            }
        }
    }
    printf("Checking minpartition %d %d %d %d %f\n",minpartition.p1.x,minpartition.p1.y,minpartition.p2.x,minpartition.p2.y,minpartition.distance);
    set finalMIN= minpartition.distance<=minset.distance?minpartition:minset;
    printf("Checking finalMIN %d %d %d %d %f\n",finalMIN.p1.x,finalMIN.p1.y,finalMIN.p2.x,finalMIN.p2.y,finalMIN.distance);
    return finalMIN;
    }
    else 
    {
        set s={{0,0},{0,0},(float)INT_MAX};
        puts("End size 0\n");
        return s;
    }
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

    qsort(X,n,sizeof(pair),compare1);
    qsort(Y,n,sizeof(pair),compare2);
    
    for(int i=0;i<n;i++){
        out(X[i].x);
        out(X[i].y);
    }
    puts("hurray\n");
    for(int i=0;i<n;i++){
        out(Y[i].x);
        out(Y[i].y);
    }
    puts("\n");

    float aa=distance(X[0],X[2]);
    printf("%f %d\n",aa,n);
     set ans=getclosestpair(X,0,n-1,Y,n);
     //printf("%d,%d -- %d,%d -- %f",ans.p1.x,ans.p1.y,ans.p2.x,ans.p2.y,ans.distance);
}