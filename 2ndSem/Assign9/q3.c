#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include<string.h>

/* max heap implementation */

/* compute child 0 or 1 */
#define Child(x, dir) (2*(x)+1+(dir))

/* float value at position pos down */
static void
floatDown(int n, int *a, int pos)
{
    int x;

    /* save original value once */
    x = a[pos];

    for(;;) {
        if(Child(pos, 1) < n && a[Child(pos, 1)] < a[Child(pos, 0)]) {
           
            if(a[Child(pos, 1)] < x) {
                a[pos] = a[Child(pos, 1)];
                pos = Child(pos, 1);
            } else {

                break;
            }
        } else if(Child(pos, 0) < n && a[Child(pos, 0)] < x) {
            
            a[pos] = a[Child(pos, 0)];
            pos = Child(pos, 0);
        } else {
            
            break;
        }
    }

    a[pos] = x;
}


static void
heapify(int n, int *a)
{
    int i;

    for(i = n-1; i >= 0; i--) {
        floatDown(n, a, i);
    }
}


void
heapSort(int n, int *a)
{
    int i;
    int tmp;

    heapify(n, a);

    for(i = n-1; i > 0; i--) {
        
        tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;

        
        floatDown(i, a, 0);
    }
}

int delete(int *n,int *a){
    int tmp=a[0];
    a[0]=a[*n-1];
    *n=*n-1;
    floatDown(*n,a,0);
    return tmp;
}

void insert(int *n,int *a,int data){
    int size=*n;
    *n=*n+1;
    a[size]=data;
    int son=size;
    int father=(size-1)/2;
    while(son>0 && a[son]<a[father])
    {
        int temp=a[son];
        a[son]=a[father];
        a[father]=temp;
        son=father;
        father=(father-1)/2;
    }

}

#define N (100)
#define MULTIPLIER (17)

int
main(int argc, char **argv)
{
    int n;
    scanf("%d",&n);
    int a[1000];
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    int k;
    puts("Enter the threshold");
    scanf("%d",&k);
    heapify(n,a);
    
    while(a[0]<k)
     {
         if(n>2){
             int t1=delete(&n,a);
            int t2=delete(&n,a);
            int t3=t1+2*t2;
            insert(&n,a,t3);
        }
        else {
            puts("Cant make the cookies any sweeter, cuz ran out of cookies");
        }
    }
    
    for(int i=0;i<n;i++){
        printf("%d,",a[i]);
    }
    puts("");

}