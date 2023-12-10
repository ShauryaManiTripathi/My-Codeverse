#include<iostream>
#include<algorithm>
using namespace std;

int compare(string a,string b){
	bool B=true;
	return a.find(b)==0?(B):(b.find(a)==0?(!B):(b>a));
}
int main() {
	int n;
	cin>>n;
    cin.get();
	string s[n];
	for(int i=0;i<n;i++){
		getline(cin,s[i]);
	}
	sort(s,s+n,compare);
    for(string a:s){
        cout<<a<<endl;
    }
	return 0;
}