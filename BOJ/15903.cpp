#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long 
int main(){
	fastio;
	int N,M; cin>>N>>M;
	ll card[1001], sum = 0;
	for(int i=0;i<N;i++) cin>>card[i];
	for(int i=0;i<M;i++){
		sort(card,card+N);
		ll tmp = card[0] + card[1];
		card[0] = card[1] = tmp;
	}	
	for(int i=0;i<N;i++) sum += card[i];
	cout<<sum;
}