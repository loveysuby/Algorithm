
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pii pair<int,int>
bool compare(pii a, pii b){
	if(a.first == b.first)
		return a.second < b.second;
	else
		return a.first < b.first;
}
int main(){
	fastio;
	vector<pii> v;
	int N; cin>>N;
	for(int i=0;i<N;i++){
		int tmp1,tmp2; cin>>tmp1>>tmp2;
		v.push_back({tmp1,tmp2});
	}
	sort(v.begin(),v.end(),compare);
	for(auto i : v)
		cout<<i.first<<' '<<i.second<<'\n';
}