#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

int multiply(char *a,char *b){
    int n1=strlen(a);
    int n2=strlen(b);
    int *result = (int *)calloc((n1+n2),sizeof(int));
    int carry=0;
    int k=0;
    for(int i=n1-1;i>=0;i--){
        int num1=a[i]-'0';
        int ktemp=k;
        for(int j=n2-1;j>=0;j--){
            int num2=b[j]-'0';
            int product=num1*num2+carry+result[ktemp];
            result[ktemp]=product%10;
            carry=product/10;
            ktemp++;
        }
        while(carry){
            result[ktemp++]=carry%10;
            carry/=10;
        }
        k++;
    }
    for(int i=n1+n2-1;i>=0;i--){
        printf("%d",result[i]);
    }
}

    

int main(){
    char a[100],b[100];
    scanf("%s",a);
    scanf("%s",b);
    printf("%s\n",a);
    printf("%s\n",b);
    multiply(a,b);
}