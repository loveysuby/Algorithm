#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
bool isPrime(int x){
	if(x<2) return false;	
	for(int i=2;i*i<=x;i++)
		if(x% i == 0){ return false;}	
	return true;
}
int main(){
	fastio;
	int M, N; cin>>M>>N;
	int min = M, sum = 0;
	
	while(M<=N){
		if(isPrime(M)) {
			min = M; break;	
		}
		M++;
	}
	while(M<=N){
		if(isPrime(M)) sum+=M;
		M++;
	}
	if(sum) cout<<sum<<'\n'<<min;
	else cout<<-1;
}