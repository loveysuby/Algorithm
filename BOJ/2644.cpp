#include <bits/stdc++.h>
//Define
using namespace std;

//Global elements
vector<int> adj[101];
int level[101];
int x,y;
//Function
int Solve(){
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		int curr = q.front();
		q.pop();
		if(curr == y)
			return level[curr];
		for(int i=0;i<adj[curr].size();i++){
			if(level[adj[curr][i]]) 
				continue;
			q.push(adj[curr][i]); 
			level[adj[curr][i]] = level[curr]+1; 	
		}
	}
	return -1;
}

//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	int size; cin>>size;
	cin>>x>>y;	
	int edges; cin>>edges;
	
	for(int i=0;i<edges;i++){
		int node1, node2;
		cin>>node1>>node2;
		adj[node1].push_back(node2);
		adj[node2].push_back(node1);
	}
	
	cout<<Solve();
    return 0;
}
