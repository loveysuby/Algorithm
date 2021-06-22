#include <bits/stdc++.h>
//Define
using namespace std;

//Global elements
int nodeCnt,edgeCnt;
vector<vector<int>> adj;
vector<bool> vis;
int component = 0;
//Function
void dfs(int node){
	vis[node] = true;
	for(auto x : adj[node]){
		if(!vis[x])
			dfs(x);	
	}	
}
//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>nodeCnt>>edgeCnt;
	adj.resize(nodeCnt+1);
	vis.resize(nodeCnt+1);
	
	while(edgeCnt--){
		int ptx,pty; cin>>ptx>>pty;
		adj[ptx].push_back(pty);
		adj[pty].push_back(ptx);
	}
	
	for(int i=1;i<=nodeCnt;i++){
		if(vis[i]) continue;
		dfs(i);
		component++;
	}	
	cout<<component;
	
    return 0;
}
