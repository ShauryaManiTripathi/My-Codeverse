#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int **Create_2d_Array(int a,int b){
    int **arr=(int**)malloc(a*sizeof(int*));
    for(int i=0;i<a;i++){
        arr[i]=(int*)malloc(b*sizeof(int));
        for(int j=0;j<b;j++)scanf("%d",&arr[i][j]);
    }
    return arr;
}

void Print_2d_Array(int **arr,int a,int b){
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++)printf("%d ",arr[i][j]);
        printf("\n");
    }
}

int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    int **arr=Create_2d_Array(a,b);
    Print_2d_Array(arr,a,b);


}
  