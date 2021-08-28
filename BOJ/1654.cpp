#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
int lan[10001], K, N;
int main()
{
    fastio;
	cin>>K>>N;
	for(int i=0;i<K;i++)
		cin>>lan[i];
	sort(lan,lan+K);
	ll res = 1, st = 1, end = lan[K-1], mid = (st+end) / 2;
	while(st<=end){
		ll tmp = 0;
		for(int i=0;i<K;i++)
			tmp += lan[i] / mid;
		if(tmp<N){
			end = mid - 1;
			mid = (st+end) / 2; 
		}
		else{
			res = max(res,mid);
			st = mid + 1;
			mid = (st+end) / 2; 
		}
	}
	cout<<res<<'\n';
    return 0;
}