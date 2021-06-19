#include <bits/stdc++.h>
//Define
using namespace std;

//Global elements
int edges;
bool vis[101];
vector<int> adj[101];
//Function
void Solve(int n){
	if(!vis[n]){
		vis[n] = true;
		edges++;
	}	
	for(int i = 0;i<adj[n].size();i++)
		if(!vis[adj[n][i]])
			Solve(adj[n][i]);	
}
//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	int size, lineCnt; 	
	cin>>size>>lineCnt;	
	for(int i=0;i<lineCnt;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}	
	Solve(1);
	cout<<edges-1;
    return 0;
}
