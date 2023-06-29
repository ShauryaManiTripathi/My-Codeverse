#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{int *va;int size;int curr;} vector_t,Vector;
vector_t hellow;
void incvect(){
    hellow.va=(int *)realloc(hellow.va,2*hellow.size*sizeof(int));
    hellow.size*=2;
    
}
void insert(int num){
    if(hellow.curr+1==hellow.size)incvect();
    hellow.va[++hellow.curr]=num;
}
void print(){
    int t=1,count=0;
    for(int i=1;i<=hellow.curr;i++){
    count++;
    printf("%d ",hellow.va[i]);
    if(count==t){puts("");t+=1+t;}
    }
}
void swap(int *a,int *b){
    int temp=*b;
    *b=*a;
    *a=temp;
}
void makeheaped(int t){
 if(t>1){
    int thalf=t/2;
    if(hellow.va[t]>hellow.va[thalf]){
        swap(hellow.va+t,hellow.va+thalf);
        makeheaped(thalf);
    }
 }
}
void heapify(int *arr,int n,int i){
    int l=2*i;
    int r=2*i+1;
    int largest=i;
    if(r<=n && arr[largest]<arr[l])
    {
        largest=l;
    }
    if(r<=n && arr[largest]<arr[r])
    {
        largest=r;
    }
    if(largest!=i){
        swap(arr+largest,arr+i);
        heapify(arr,n,largest);
    }

}
///////////////////////////////////////////////////////

void insertandcheck( int temp){
    insert(temp);
    makeheaped(hellow.curr);
}
////////////////////////////////////////////////////

void heapifyMASTER(){
    for(int i=(hellow.curr-1)/2;i>0;i--){
        heapify(hellow.va,hellow.curr,i);
    }
}
//////////////////////////////////////////////////////////

int delete(int index){
    if(index>hellow.curr)puts("out of bounds deletion");
    int temp=hellow.va[index];
    if(index!=hellow.curr){
    swap(&hellow.va[index],&hellow.va[hellow.curr]);
    }
    hellow.curr--;
    heapifyMASTER();
   // printf("Element deleted:%d\n",temp);
}
/////////////////////////////////////////////////////////

int main(){
    hellow.size=1;
    hellow.curr=0;
    hellow.va=(int *)malloc(sizeof(int));
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int temp;
        scanf("%d",&temp);
        insert(temp);
        //makeheaped(i);
    }
    puts("\nthe array is\n");
    print();
    heapifyMASTER();
    puts("\nAfter master heapify, the heap is\n");
    print();
    printf("\nCurrent stats::currindex->%d currsize->%d\n",hellow.curr,hellow.size);

    puts("\nEnter a number, to find n'th largest");
    int temp;
    scanf("%d",&temp);
    for(int i=1;i<temp;i++){
        delete(1);
        //puts("");
        //print();
    }
    printf("\n The %d'th largest element is %d",temp,hellow.va[1]);

}
