#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
	fastio;
	int N,res = 0; cin>>N; N = 1000 - N;
	int c[6] = {500,100,50,10,5,1};
	for(int i=0;N>0;i++){
		res += N/c[i];
		N %= c[i];
	}
	cout<<res;
}