#include<iostream>
using namespace std;

int increment1(float a){
    return a+1;
}

void increment2(float *a){
    *a=*a+1;
}



int main(){  
    int x=5;
    float y=10;
    char s='a';
    cout<<&x<<"  "<<&y<<"  "<<&s<<endl;

    //&s gives a on output, because of operator overloading because of '<<' operator

    cout<<(void *)&s<<endl;// now we can get it back

    //(void *) is example of EXPLICIT TYPECASTING

    cout.flush();

    //Here We Begin POINTER
    // *(ptr) is used to dereference the pointer variable
    // like 
    cout<<*(&s)<<endl;
    y=increment1(y);
    cout<<y<<endl;
    increment2(&y);
    cout<<y<<endl;
    

    
}