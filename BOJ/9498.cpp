#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
	fastio;
	char s;
	int N; cin>>N;
	if(N>=90 && N<=100) s='A';
	else if(N>=80 && N<90) s='B';
	else if(N>=70 && N<80) s='C';
	else if(N>=60 && N<70) s='D';
	else s='F';
	cout<<s;
}