// Sanket has a string consisting of only 'a' and 'b' as the characters.
// Sanket describes perfectness of a string as the maximum length substring of equal characters.
// Sanket is given a number **k** which denotes the maximum number of characters he can change.
// Find the maximum perfectness he can generate by changing no more than **k** characters.
// Input Format: The first line contains an integer denoting the value of K.
// The next line contains a string having only ‘a’ and ‘b’ as the characters.
// Sample Input: 2
// abba
// Output Format: A single integer denoting the maximum perfectness achievable.
// Sample Output: 4
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin.get();
    getline(cin,s);
    //char *ss=(char*)s.c_str();


    vector<int> a;
    int sum=0,suma=0,sumb=0;
    for(int i=0;i<s.length();i++){
        if(s.at(i)=='a'){
            sum++;
        }
        else{
            a.push_back(sum);
            suma+=sum;
            sum=0;
        }
    }
    a.push_back(sum);
    suma+=sum;
    sum=0;


    vector<int> b;
    for(int i=0;i<s.length();i++){
        if(s.at(i)=='b'){
            sum++;
        }
        else{
            b.push_back(sum);
            sumb+=sum;
            sum=0;
        }
    }
    b.push_back(sum);
    sumb+=sum;
    sum=0;


    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<b.size();i++){
        cout<<b[i]<<" ";
    }
    cout<<endl;
    int cand1=0,cand2=0;
    {
        if(a.size()<=n+1){
            cand1=suma+a.size()-1;
        }
        else {
            int tempsum=n;
            for(int i=0;i<a.size();i++){
                if(i<=n){
                    tempsum+=a[i];
                }
                else{
                    tempsum+=a[i]-a[i-n-1];
                }
                if(cand1<tempsum)cand1=tempsum;
            }
        }
    }
    {
        if(b.size()<=n+1){
            cand2=sumb+b.size()-1;
        }
        else {
            int tempsum=n;
            for(int i=0;i<b.size();i++){
                if(i<=n){
                    tempsum+=b[i];
                }
                else{
                    tempsum+=b[i]-b[i-n-1];
                }
                if(cand2<tempsum)cand2=tempsum;
            }
        }
    }
    cout<<(cand1>cand2?cand1:cand2);


}


