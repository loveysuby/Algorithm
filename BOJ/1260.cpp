//Header
#include <bits/stdc++.h>
//Define
using namespace std;

//Global elements

int chkdfs[1001];
int chkbfs[1001]; 

// equal for vector<vector<int>> vec(1001,0); 행의 수 == 정점 개수
vector<int> edge[1001]; 

//Function
void dfs(int x){
	cout<<x<<' ';
	chkdfs[x]=1;
	for(auto n:edge[x]){		
		if(chkdfs[n]==0){
			chkdfs[n]=1;
			dfs(n);
		}
	}
}

void bfs(int x){
	chkbfs[x]=1;
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		x = q.front();
		q.pop();
		cout<<x<<' ';
		for(auto n:edge[x]){
			if(chkbfs[n]==0){
				chkbfs[n]=1;
				q.push(n);
			}
		}
	}	
}

//Driver
int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	int nodeCnt,edgeCnt,first;
	int nx,ny;
	
	cin>>nodeCnt>>edgeCnt>>first;
	
	for(int i=1;i<=edgeCnt;i++){
		cin>>nx>>ny;
		edge[nx].push_back(ny);
		edge[ny].push_back(nx);
	}
	for(int i=1;i<=nodeCnt;i++)
		sort(edge[i].begin(),edge[i].end());
	
	dfs(first);
	cout<<"\n";
	bfs(first);
	
	return 0;
}
