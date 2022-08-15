#include <bits/stdc++.h>
using namespace std;
int N,M, component,maxSize;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int arr[501][501];
bool vis[501][501];
int bfs(int i, int j){	
	vis[i][j] = 1;
	queue<pair<int,int>> q;
	q.push({i,j});
	int temp = 1;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i = 0;i<4;i++){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx<0||nx>=N||ny<0||ny>=M) continue;
			if(vis[nx][ny]|| !arr[nx][ny]) continue;
			vis[nx][ny] = 1;
			temp++;
			q.push({nx,ny});
		}		
	}
	return temp;	
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	for(int i = 0;i<N;i++)
		for(int j = 0;j<M;j++)
			cin>>arr[i][j];
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(!vis[i][j] && arr[i][j]){
				maxSize = max(maxSize,bfs(i,j));
				component++;
			}
		}
	}
	cout<<component<<'\n'<<maxSize<<'\n';	
    return 0;
}