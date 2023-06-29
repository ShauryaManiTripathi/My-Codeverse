#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

bool compare(string a,string b){
    if(a.length()==b.length())return a<b;//if string length are same, compare on lexographical order
    return a.length()>b.length();
}
int main(){
    int n;
    cin>>n;
    cin.get();// here its used to consume a enter error, as first string get setted as only enter in loop at line number 14
    cout<<n<<endl;
    //cin.get() has two optional parameters, reads a character or characters based on parameters   //n=cin.get() <-- returns charater received
    //its declaration looks like return char cin.get(char*addr,int t=1),, so two optional params 
    string s[100];

    for(int i=0;i<n;i++){
        getline(cin,s[i]);
        //cin.getline does not work for string class, rather we need to use a chord of getline using following parameters
    }
    
    sort(s,s+n); 

    //by default , when we compare strings , the comparison is based on lexographical order. i.e. s[i]>s[j] will get overloaded with str.compare(str2)
    //Here, we are sorting strings, not characters of string
    cout<<"default lexo comparison\n"; 
    for(int i=0;i<n;i++){
        cout<<s[i]<<endl;
    }

    sort(s,s+n,compare); 

    //using compare
    cout<<"using compare\n";
    for(int i=0;i<n;i++){
        cout<<s[i]<<endl;
    }

    
}