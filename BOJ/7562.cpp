#include <bits/stdc++.h>
using namespace std;
//Global elements
int N,start_x,start_y,dest_x,dest_y;
int dx[] = {2,2,-2,-2,1,1,-1,-1};
int dy[] = {1,-1,1,-1,2,-2,2,-2};
int dp[301][301];
//Function
void solve(){
	queue<pair<int,int>> q;
	q.push(make_pair(start_x,start_y));
	while(!q.empty()){
		int x = q.front().first, y = q.front().second; 
		q.pop();
		if(x==dest_x && y==dest_y){
			cout<<dp[x][y]<<'\n';
			return;
		}
		for(int i=0;i<8;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx<0||nx>=N||ny<0||ny>=N) continue;
			if(dp[nx][ny]) continue;
			dp[nx][ny] = dp[x][y]+1;
			q.push(make_pair(nx,ny));
		}
	}
}
//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	int T; cin>>T;
	while(T--){
		cin>>N;
		cin>>start_x>>start_y>>dest_x>>dest_y;
		memset(dp,0,sizeof(dp));
		solve();
	}
    return 0;
}