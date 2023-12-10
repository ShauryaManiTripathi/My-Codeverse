#include<iostream>
#include<algorithm>
using namespace std;

int maskApply(int n,int mask,int operation){
    switch(operation){
        case 1: return n&(~mask);
                break;
        case 2: return n^mask;
                break;
        case 3: return n|mask;
                break;
        default:return n;
    }
}

int main(int argc, char const *argv[])
{
    // bitwise operators include | & ^ ~, but also include >> << ,
    // which must be different from cin's <<. it gets overloaded just like +,-
    int t=__INT_MAX__;

    t= t<<4;
    cout<<t;
    t= __INT_MAX__+1;
    cout<<t<<endl;

    //------------------------------------------------------------------------
    int n=15; //last four bits positive  1111
    cout<<0xf<<"="<<0b1111<<"="<<017<<endl;
    int mask=1<<2;//third bit positive 0100
    int n_copy=n;
    cout<<"N="<<n<<endl;
    //lets reset the third bit
    cout<<(n&(~mask))<<endl;
    //lets flip the third bit
    cout<<(n^(mask))<<endl;
    //lets set the third bit
    cout<<(n|mask)<<endl;






    return 0;
}

