#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

int precedence(char temp){
    switch(temp){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

int associativity(char temp){
    switch(temp){
     case '+':
     case '-':
     case '*':
     case '/':
     return 1;
     default:
     return 0;
    }
}

char *getstring(){
    fflush(stdin);
    char buffer[10000];
    scanf("%[^\n]s",buffer);
    int n=strlen(buffer);
    char *infix = (char *)malloc(n*sizeof(char));
    strcpy(infix,buffer);
    return infix;
}

int BinaryEvaluator(int a,int b,char c){
    switch(c){
            case '+':return a+b;
            case '-':return a-b;
            case '*':return a*b;
            case '/':return a/b;
            case '^':return (int)pow((double)a,(double)b);
            default: exit(0);
        }
}


int main(){
    char *infix=getstring();
    puts(infix);
    char operand[100];
    int *terms=(int *)calloc(101,sizeof(int));
    int count=0;
    int n=strlen(infix);
    printf("strlen::%d\n",n);
    for(int i=0;i<=n;i++){
        if(!isdigit(infix[i]) || infix[i]=='\0'){
            operand[count++]=infix[i];
        int i1=i-1;
        int mult=1;
        while(i1>=0 && isdigit(infix[i1])){
            terms[count-1]+=(infix[i1]-'0')*mult;
            mult*=10;
            i1--;
        }
        }
    }
    count--;
    printf("count of operand::%d\n",count);
    puts("operands in sequence");
    for(int i=0;i<count;i++){
        printf("%c,",operand[i]);
    }
    puts("");
    puts("terms in sequence");
    for(int i=0;i<count+1;i++){
        printf("%d,",terms[i]);
    }
    puts("");
    while(count){
        int OPpoint=0;
        for(int i=0;i<count;i++){
           if(associativity(operand[OPpoint])){
            if(precedence(operand[OPpoint])<precedence(operand[i]))
            OPpoint=i;
           }
           else{
            if(precedence(operand[OPpoint])<=precedence(operand[i]))
            OPpoint=i;
           }
        }
        printf("OPpoint--%d\nOPerand--%c\n",OPpoint,operand[OPpoint]);
        int temp=BinaryEvaluator(terms[OPpoint],terms[OPpoint+1],operand[OPpoint]);
        // switch(operand[OPpoint]){
        //     case '+':temp=terms[OPpoint]+terms[OPpoint+1];
        //     break;
        //     case '-':temp=terms[OPpoint]-terms[OPpoint+1];
        //     break;
        //     case '*':temp=terms[OPpoint]*terms[OPpoint+1];
        //     break;
        //     case '/':temp=terms[OPpoint]/terms[OPpoint+1];
        //     break;
        //     case '^':temp=pow((double)terms[OPpoint],(double)terms[OPpoint+1]);
        //     break;
        //     default: exit(0);
        // }
        printf("Test::%d\n",temp);
        terms[OPpoint]=temp;
        for(int i=OPpoint;i<count;i++){
            operand[i]=operand[i+1];
            terms[i+1]=terms[i+2];
        }
        count--;
    }
    infix=getstring();
    printf("Answer::%d",terms[0]);
}



