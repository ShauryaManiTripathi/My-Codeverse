#include<iostream>
using namespace std;
int main() {
	int n,final=0;
	cin>>n;
	while(n--){
		int temp;
		cin>>temp;
		final=final^temp;
	}
	cout<<final<<endl;
	return 0;
}