#include<iostream>
#include<algorithm>
#include<bitset>

using namespace std;

int applyMask(int n,int mask,int operation){// to do operatiom, send mask , which bits =1 on which we have to do operation, i.e. if u gonna set/flip/reset 3rd and 2nd bit, send ........000110
    switch(operation){
        case 1: return n&(~mask);//reset
                break;
        case 2: return n^mask;//flip
                break;
        case 3: return n|mask;//set
                break;
        default:return n;
    }
}
int checkBit(int n,int i){
    return (n>>(i-1))&1;
}

void clearRange(int &n,int j,int i){
    int mask=((~0)<<j)|((1<<i)-1);//how to make range mask, starting at but of order J and ending befor e but of order i; i.e. for ....0000110, j=3,i=1; it will generate invert mask = ......111111001
    n=n&mask;
}

//implement count setbits

int main(int argc, char const *argv[])
{
    // bitwise operators include | & ^ ~, but also include >> << ,
    // which must be different from cin's <<. it gets overloaded just like +,-
    int t=__INT_MAX__;

    t= t<<4;
    cout<<t<<endl;//line 1
    t= __INT_MAX__+1;
    cout<<t<<endl;//line 2

    //------------------------------------------------------------------------
    int n=15; //last four bits positive  1111
    cout<<0xf<<"="<<0b1111<<"="<<017<<endl;//line 3
    int mask=1<<2;//third bit positive 0100
    int n_copy=n;
    cout<<"N="<<n<<endl;//line 4
    //lets reset the third bit
    cout<<(n&(~mask))<<endl;//line 5
    //lets flip the third bit
    cout<<(n^(mask))<<endl;//line 6
    //lets set the third bit
    cout<<(n|mask)<<endl;//line 7


    //check odd / even
    t=3;
    //1 if bitset<32> z1((__INT_MAX__+1)>>5);odd
    cout<<"3 is "<<(t&1)<<" while 4 is "<<((t+1)&1)<<endl;//line 8

    //checks if state of a bit (set or reset)
    cout<<checkBit(0x8,4)<<" - "<<checkBit(0x7,4)<<endl;//line 9

    bitset<32> x(~0);
    cout<<(x)<<endl;//line 10

    int test=~0;//signed integer
    test=(~0)<<21;
    bitset<32> y(((test)<<10)>>5);//right shift causes MSB to be copied to shifted digits, in signed integer or number
    bitset<32> z(((unsigned)(test)<<10)>>5);
    bitset<32> z1((__INT_MAX__+1)>>5);
    bitset<32> z2((unsigned)(__INT_MAX__+1)>>5);
    bitset<32> z3((0)>>5);


    cout<<y<<endl;//line 11
    cout<<z<<endl;//line 12
    cout<<z1<<endl<<z2<<endl<<z3<<endl;// line 13 14 15
    
    int p=15;
    clearRange(p,3,1);
    cout<<p<<endl;//line 16

    //now similarly, we can update some order of bits in any var N with bits in var M
    //we can use clearRange to generate our masks too
    int N=63;// ....00111111
    int M=15;// ....00001111
    //updating         ^^    of N with m,
    //lets create mask from j before i
    mask=(~0);
    clearRange(mask,5,3); //......11100111;
    mask=~mask;           //......00011000;
    //now
    clearRange(N,5,3);//resetted bit range from 5 to 3
    bitset<32> y1(N);
    cout<<y1<<endl;//line 17
    M=applyMask(M,~mask,1);
    bitset<32> y2(M);
    cout<<y2<<endl;//line 18

    N=N|M;
    
    bitset<32> y3(N);
    cout<<y3<<endl;//line 19


    unsigned int t_=-1;
    bitset<32> tt(t_);
    cout<<t_<<endl;//line 20

    return 0;
    //decimalToBinary
    //decimal to binary bitwise7

    // create a unsigned int mask, with MSB=1 ,rest 0
    // now take bitwise & with the number, if its >0, print 1, otherwise 0 , then right shift mask and repeat
    // while operating with negative numbers, ignore singned bit, 
    // assume positive number and start masking from 31th bit

    
}

