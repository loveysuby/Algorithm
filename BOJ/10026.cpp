#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

//Global elements
char s[101][101];
bool vis[101][101];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int N;
//Function
int bfs(short flag){
	//색약인 경우 G를 R로 대체함
	if(flag){
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				if(s[i][j]=='G') s[i][j] = 'R';
	}
	int component = 0;
	queue<pair<int, int>> q;	
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			//완탐 : 들어오는 노드를 큐에 넣고 방문처리함
			if(!vis[i][j]){
				q.push({i,j});
				vis[i][j] = true;
				//bfs 돌려서 인접 색상과 같은 것의 series는 동일 컴포넌트에 해당 됨
				while(!q.empty()){
					int x = q.front().first, y = q.front().second;
					q.pop();
					for(int k=0;k<4;k++){
						int nx = x+dx[k], ny = y+dy[k];	
						if(nx<0||nx>=N||ny<0||ny>=N) continue;
						if(!vis[nx][ny] && s[nx][ny] == s[i][j]){
							q.push({nx,ny});
							vis[nx][ny] = true;
						}
					}
				}
				//bfs 끝 
				component++;
			}	
	memset(vis,false,sizeof(vis));
	return component;
}
//Driver
int main()
{
	fastio;
	cin>>N;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin>>s[i][j];
	cout<<bfs(0)<<' '<<bfs(1);
	return 0;
}