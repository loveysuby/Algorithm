#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
int main()
{
	fastio;
	int N; cin>>N;
	vector<ll> dist(N);
	priority_queue<ll,vector<ll>,greater<ll>> price;
	for(int i=0;i<N-1;i++)
		cin>>dist[i];
	
	ll tmp, min_p=0;
	for(int i=0;i<N;i++){
		cin>>tmp;
		price.push(tmp); // price.top = min_p
		min_p += price.top() * dist[i];
	}
	cout<<min_p;
	return 0;
}