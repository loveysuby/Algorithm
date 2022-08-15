#include <bits/stdc++.h>
using namespace std;
int N,M;
int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
int result = 0;
void bfs_getCurrCnt(vector<vector<int>> &vec){	
	queue<pair<int,int>> q;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			if(vec[i][j]==2)
				q.push({i,j});	
	while(!q.empty()){
		int x = q.front().first, y = q.front().second;
		q.pop();
		for(int i =0 ; i<4; i++){
			int nx = x + dx[i], ny = y + dy[i];
			if(nx<0||nx>=N||ny<0||ny>=M) continue;
			if(vec[nx][ny] == 0){
				vec[nx][ny] = 2;
				q.push({nx,ny});
			}
		}
	}
	int cnt = 0;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			if(vec[i][j]==0) 
				cnt++;	
	result = max(result,cnt);
}
void solve(vector<vector<int>> vec, int x, int y, int cnt){
	vec[x][y] = 1;
	if(cnt==0){
		bfs_getCurrCnt(vec);
		return;
	}
	for(int i=x;i<N;i++)
		for(int j=0;j<M;j++)
			if(vec[i][j]==0)
				solve(vec,i,j,cnt-1);
}
int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>N>>M;
	vector<vector<int>> v(N,vector<int>(M));
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			cin>>v[i][j];
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			if(v[i][j]==0)
				solve(v,i,j,2);	
	cout << result;	
	return 0;
}