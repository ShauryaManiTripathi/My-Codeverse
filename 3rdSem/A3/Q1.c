#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<limits.h>
#include<math.h>

#pragma message ("use -lm for compiling on linux with older gcc versions")
#pragma message ("C is single thread program by default, thus tho i am deallocating the return array in find_MaxMin_DnC function, the values wont be changed before printing as no user end modification is done and heap memory is reserved for c program exclusively")

int Max(int a,int b){
    return a>b?a:b;
}

int find_Max_DnC(int *a,int size){
    if(size==1){
        return a[0];
    }
    else {
        int size1=size/2;
        return Max(find_Max_DnC(a,size1),find_Max_DnC(a+size1,size-size1));
    }
}

int* find_MAXnMIN_DnC(int *a,int size){
    int *returnval=(int *)calloc(2,sizeof(int));
    switch(size){
        case 1:{
            returnval[0]=a[0];
            returnval[1]=a[0];
            return (int *)returnval;
            break;
        }
        case 2:{
            returnval[0]=a[0]>a[1]?a[0]:a[1];
            returnval[1]=a[1]>a[0]?a[0]:a[1];
            return (int *)returnval;
            break;
        }
        default:{
            int size1=size/2;
            int *set1=find_MAXnMIN_DnC(a,size1);
            int *set2=find_MAXnMIN_DnC(a+size1,size-size1);
            returnval[0]=set1[0]>set2[0]?set1[0]:set2[0];
            returnval[1]=set1[1]>set2[1]?set2[1]:set1[1];
            return (int *)returnval;
        }
        
    }
    free(returnval);
}

int* find_MAXn2ndMAX_DnC(int *a,int size){
    int *returnval=(int *)calloc(2,sizeof(int));
    switch(size){
        case 1:{
            returnval[0]=a[0];
            returnval[1]=a[0];
            return (int *)returnval;
            break;
        }
        case 2:{
            returnval[0]=a[0]>a[1]?a[0]:a[1];
            returnval[1]=a[1]>a[0]?a[0]:a[1];
            return (int *)returnval;
            break;
        }
        default:{
            int size1=size/2;
            int *set1=find_MAXn2ndMAX_DnC(a,size1);
            int *set2=find_MAXn2ndMAX_DnC(a+size1,size-size1);
            int largest,secondlargest;
            largest=set1[0]>set2[0]?set1[0]:set2[0];
            //printf("test %d,%d test2 %d,%d\n",set1[0],set1[1],set2[0],set2[1]);
            secondlargest=largest==set1[0]?(set1[1]>set2[0]?set1[1]:set2[0]):(set1[0]>set2[1]?set1[0]:set2[1]);
            returnval[0]=largest;
            returnval[1]=secondlargest;
            return (int *)returnval;
        }
        
    }
    free(returnval);
}

int* find_MAXn2ndMAX_DnCv2(int *a,int size){
    int *returnval=(int *)calloc(2,sizeof(int));
    switch(size){
        case 1:{
            returnval[0]=a[0];
            returnval[1]=INT_MIN;
            return (int *)returnval;
            break;
        }
        case 2:{
            returnval[0]=a[0]>a[1]?a[0]:a[1];
            returnval[1]=a[1]>a[0]?(a[0]==returnval[0]?INT_MIN:a[0]):(a[1]==returnval[0]?INT_MIN:a[1]);
            return (int *)returnval;
            break;
        }
        default:{
            int size1=size/2;
            int *set1=find_MAXn2ndMAX_DnCv2(a,size1);
            int *set2=find_MAXn2ndMAX_DnCv2(a+size1,size-size1);
            int largest,secondlargest;
            largest=set1[0]>set2[0]?set1[0]:set2[0];
            //printf("test %d,%d test2 %d,%d\n",set1[0],set1[1],set2[0],set2[1]);
            secondlargest=largest==set1[0]?(set1[1]>set2[0]?set1[1]:set2[0]):(set1[0]>set2[1]?set1[0]:set2[1]);
            returnval[0]=largest;
            returnval[1]=secondlargest;
            return (int *)returnval;
        }
        
    }
    free(returnval);
}

int main(){
    int a[10];
    for (int i = 0; i < 10; i++)
    {
        a[i]=10-i;
        printf("%d ",a[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        a[i]=10-i;
        printf("%d ",a[i]);
    }
    a[1]=10;
    puts("");

    printf("MAX:::%d\n",find_Max_DnC(a,10));
    int *maxmin=find_MAXnMIN_DnC(a,10);
    printf("MAX:::%d   MIN:::%d\n",maxmin[0],maxmin[1]);
    maxmin=find_MAXn2ndMAX_DnC(a,10);
    printf("First CHAMPION:::%d   Second CHAMPION:::%d\n",maxmin[0],maxmin[1]);
    maxmin=find_MAXn2ndMAX_DnCv2(a,10);
    printf("First MAX:::%d   Second MAX:::%d\n",maxmin[0],maxmin[1]);

    
}