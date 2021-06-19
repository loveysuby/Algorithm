#include <bits/stdc++.h>
//Define
using namespace std;

//Global elements
vector<int> adj[101];
int level[101]
int x,y,res = -1;
//Function
int Solve(){
	queue<int> q;
	q.push(x);
	while(q.isEmpty();){
		int curr = q.front();
		q.pop();
		if(curr == y) return level[curr];		
		for(int i=0;i<adj[x].size();i++){
			if(level[adj[curr][i]]==0){
				q.push(adj[curr][i]); 
				level[adj[curr][i]] = level[curr]++; 	
			}
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
		int x,y; cin>>x>>y;
		adj[x].pushback(y);
		adj[y].pushback(x);
	}
	
	cout<<Solve();
    return 0;
}
