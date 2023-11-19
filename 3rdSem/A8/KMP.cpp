#include <bits/stdc++.h>
using namespace std;

void calculatePi(char pat[], int pi[],int m)
{
	pi[0] = 0;
	int len = 0;
	for(int i=1;i<m;i++){
		if(pat[len]==pat[i]){
			len++;
			pi[i]=len;
		}
		else if(len!=0){
			len=pi[len-1];
			i--;
		}
		else{
			pi[i]=0;
			//you are here, it implies the current letter didnt match as well as len is zero
		}
	}	
}

void HuntPattern(char str[], char pat[])
{
	int n = strlen(str);
	int m = strlen(pat);
	int pi[m];
	calculatePi(pat, pi, m);
	int i=0,j=0;
	while(i<n){
		if(str[i]==pat[j]){
			i++;
			j++;
		}
		if(j==m){
			cout<<"Hunted down one at index = "<<i-j<<endl;
			j=pi[j-1];
		}
		else if(i<n && str[i]!=pat[j]){
			if(j!=0)
				j=pi[j-1];
			else
				i++;
		}
	}
	
}
int main(int argc, char const *argv[])
{
	char str[1000] = "Nitin Nitisha Nipples Nitor siNitor";
	char pat[1000] = "Nit";
	HuntPattern(str, pat);
	return 0;
}
