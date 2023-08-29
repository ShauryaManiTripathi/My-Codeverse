#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include<ctype.h>


/*SAMPLE INPUT
10
-100 -90
-1200 -1110
5 9
-1100 -900
7 9
1 9
21 45
31 69
41 42
0 1
*/

/*SAMPLE INPUT
10
-100 -90
-1200 -1110
5 9
-1150 -900
7 9
1 9
21 45
31 69
41 42
0 1
*/



#pragma pack(1)

#define in(x) scanf("%d",&x);
#define out(x) printf("%d \t",x);

typedef struct interval{
    int l;
    int r;
} interval;

int compare(const void *p1,const void *p2){
    return ((interval *)p1)->l>((interval *)p2)->l;
}

int get_max_intersecting_intervals(interval *arr,int size,interval *set1,interval *set2){
    int MaxR=0,max_intersect_width=0;
    
    for(int i=1;i<size;i++){
        if(arr[MaxR].r<arr[i-1].r)MaxR=i-1;
        int intersect_width=((arr[MaxR].r>arr[i].l)
                                                    ?
                                                    ((arr[MaxR].r<arr[i].r)?
                                                                            (arr[MaxR].r-arr[i].l)
                                                                            :
                                                                            (arr[i].r-arr[i].l))
                                                    :
                                                    0);
        if(intersect_width>=max_intersect_width){
            max_intersect_width=intersect_width;
            *set1=arr[MaxR];
            *set2=arr[i];
        }
    }
    return max_intersect_width;
}



int main(){
    int n;
    puts("enter the number of intervals ");
    in(n)
    interval set[n];

    printf("You need to enter %d number of inputs depicting interval's left hand size and right hand side alternatively\n",n*2);
    for(int i=0;i<n;i++){
        in(set[i].l)
        in(set[i].r)
    }

    qsort(set,n,sizeof(interval),compare);
    puts("now the following array is being sorted based on the left hand side value in ascending order");
    for(int i=0;i<n;i++){
        out(set[i].l)
        out(set[i].r)
        puts("");
    }

    interval set1,set2;
    printf("interval 1::(%d,%d)\ninterval 2::(%d,%d)\nintersection width:: %d\n",set1.l,set1.r,set2.l,set2.r,get_max_intersecting_intervals(set,n,&set1,&set2));
    
}