#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 8
int a[MAX],N,M;
void dfs(int cnt, int idx){
	if(idx == M){
		for(int i = 0; i<M;i++)
			cout<<a[i]<<' ';
		cout<<"\n";
		return;
	}
	for(int i=cnt;i<=N;i++){
		a[idx] = i;
		dfs(i, idx+1);
	}
}
int main(){
	fastio;
	cin>>N>>M;
	dfs(1,0);
}