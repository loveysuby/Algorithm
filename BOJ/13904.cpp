#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pii pair<int, int>
bool cmp(pii a, pii b){
	if(a.second == b.second) 
		return a.first<b.first;
	return a.second>b.second;
}
int main(){
	fastio;
	int N, sum = 0; cin>>N;
	pii v[1001]; int vis[1001];
	
	for(int i=0;i<N;i++)
		cin>>v[i].first>>v[i].second;
	
	sort(v,v+N+1,cmp);
	
	for(int i=0;i<N;i++){
		int idx = v[i].first;
		for(int j=idx;j>0;j--){
			if(vis[j]) continue;
			vis[j] = v[i].second;
			sum += v[i].second;
			break;
		}
	}
	cout<<sum;
}