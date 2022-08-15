#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pis pair<int, string>

bool cmp(pis p1, pis p2){
	return p1.first < p2.first;
}
int main(){
	fastio;
	int N; cin>>N;
	vector<pis> v(N);
	pis p;
	for(int i=0;i<N;i++){	
		cin>>v[i].first>>v[i].second;
	}
	stable_sort(v.begin(), v.end(),cmp);
	for(int i=0;i<N;i++){
		cout<<v[i].first<<' '<<v[i].second<<'\n';
	}
}