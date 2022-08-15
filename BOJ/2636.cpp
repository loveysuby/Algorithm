#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

//Global elements
int arr[101][101];
int N,M;
bool vis[101][101];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
//Function
int getelem(){
	int ret=0;
	for(int i=1;i<N-1;i++)
		for(int j=1;j<M-1;j++)
			if(arr[i][j]==1) ret++;
	return ret;
}
void bfs(){
	queue<pair<int,int>> q;
	memset(vis,false,sizeof(vis));
	int x = 0, y = 0;
	q.push({x,y});
	vis[x][y] = true;
	//치즈를 둘러싼 부분을 큐에 추가함 (구멍 제외)
	while(!q.empty()){
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			int nx = x + dx[i], ny = y + dy[i];	
			if(vis[nx][ny] || arr[nx][ny]) continue;
			if(nx<0||ny<0||nx>=N||ny>=M) continue;	
			q.push({nx,ny});
			vis[nx][ny] = true;
		}
	}
	
	//치즈의 테두리 부분과 인접한 치즈는 녹는다
	for(int i=1;i<N-1;i++){
		for(int j=1;j<M-1;j++){
			if(!arr[i][j]) continue;
			for(int k=0;k<4;k++){
				int nx = i + dx[k], ny = j + dy[k];
				if(vis[nx][ny]){
					arr[i][j] = 0;
					break;
				}
			}
		}
	}
		
}
//Driver
int main()
{
	fastio;
	cin>>N>>M;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			cin>>arr[i][j];
	
	int time=0, currCnt, prevCnt=0;
	
	while(1){
		currCnt = getelem();	
		if(currCnt == 0)
			break;
		else
			prevCnt = currCnt;
		bfs();
		time++;
	}
	
	cout<<time<<'\n'<<prevCnt<<'\n';
	
	return 0;
}