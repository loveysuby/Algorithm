#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
int main()
{
    fastio;
	ll N,M,elem;
	cin>>N;
	vector<ll> v(N);
	for(int i=0;i<N;i++)
		cin>>v[i];
	sort(v.begin(),v.end());
	cin>>M;
	while(M--){
		cin>>elem;
		if(binary_search(v.begin(),v.end(),elem)) cout<<"1 ";
		else cout<<"0 ";
	}
}