#include <bits/stdc++.h>
using namespace std;
#define MAX 8
int a[MAX],N,M;
void dfs(int idx){
	if(idx == M){
		for(int i = 0; i<M;i++)
			cout<<a[i]<<' ';
		cout<<"\n";
		return;
	}
	for(int i=1;i<=N;i++){
		a[idx] = i;
		dfs(idx+1);
	}
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>N>>M;
	dfs(0);
    return 0;
}