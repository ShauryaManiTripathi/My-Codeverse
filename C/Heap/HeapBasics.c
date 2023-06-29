//heap is best dealt with array
//heap is of min/max type.
//heap has functions like insertion with rearrangement
//deletion of elements with rearrangement
//insertion takes O(logn) time
//deletion takes O(logn) time
//heap is a complete binary tree
//heap is a binary tree with heap order property
//heap order property is for min heap, all childrens are greater than father
//for max heap, all childrens are smaller than father
//heap is a binary tree with complete binary tree property
//complete binary tree property is, all levels are filled except the last level
//last level is filled from left to right
//heap is represented in array
//heap is not a sorted array
//sorted array has a property, all elements are greater than its previous element
//heap is a binary tree with heap order property and complete bin
//heapify and much more
//here we can use basic array to implement but can make a pseudo vector in c to accomodate all elements
//its a bianry tree with complete binary tree property as well as its own heap order property


//if used in a array. the level order traversal takes o(n) time
//where in linked nodes , its idiotism
//VIUALIZE IT AS A TREE but process it in array
//in array, the Oth index is reserved, root is at 1 index
//for a node at i index,, the left and right childrens are respectively 2i and 2i+1

//doing insertion in heap represented in array with take o(1)
//while doing level order search in node tree is very tedious


//in a nutshell
//use array or get smarter
//in array first n/2+1 element are 2nd order node (are fathers of some nodes)

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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
        if(Child(pos, 1) < n && a[Child(pos, 1)] > a[Child(pos, 0)]) {
            /* maybe swap with Child(pos, 1) */
            if(a[Child(pos, 1)] > x) {
                a[pos] = a[Child(pos, 1)];
                pos = Child(pos, 1);
            } else {
                /* x is bigger than both kids */
                break;
            }
        } else if(Child(pos, 0) < n && a[Child(pos, 0)] > x) {
            /* swap with Child(pos, 0) */
            a[pos] = a[Child(pos, 0)];
            pos = Child(pos, 0);
        } else {
            /* done */
            break;
        }
    }

    a[pos] = x;
}

/* construct a heap bottom-up */
static void
heapify(int n, int *a)
{
    int i;

    for(i = n-1; i >= 0; i--) {
        floatDown(n, a, i);
    }
}

/* sort an array */
void
heapSort(int n, int *a)
{
    int i;
    int tmp;

    heapify(n, a);

    for(i = n-1; i > 0; i--) {
        /* swap max to a[i] */
        tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;

        /* float new a[0] down */
        floatDown(i, a, 0);
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
    heapSort(n,a);
    int count=0,temp=0;
    for(int i=0;i<n;i++){
        temp=a[i];
        int j;
        for(j=i;temp==a[j] && j<n;j++)
        {
            count++;
        }
        i=j-1;
        if(count>1){
            printf("%d has occured %d times\n",temp,count);
        }
        count=0;
    }
    for(int i=0;i<n;i++){
        printf("%d,",a[i]);
    }
}
