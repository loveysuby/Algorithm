#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
	fastio;
	int N,X; cin>>N>>X;
	vector<int> v;
	for(int i=0;i<N;i++) {
		int tmp; cin>>tmp;
		if(tmp<X) v.push_back(tmp);
	}
	for(auto x: v) cout<<x<<' ';
}