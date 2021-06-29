#include <bits/stdc++.h>
//Define
using namespace std;

//Global elements
int maze[101][101];
int visCnt[101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
//Function

//Driver
int main()
{
	// ios::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);
	
	/*
	char형태로 입력을 받아 scanf , printf 를 이용할 때, 
	ios::sync_with_stdio(false) 를 사용하면 안 된다!(적어도 BOJ에서는 그렇다.)
	WHY : 위 함수 자체가 c++ 컴파일 과정에서 c style i/o 함수를 제거함. 그래서 속도가 빨라지는 건데 저걸 써놓고 c style 입력을 사용하면 인식이 안 됨!
	*/
	int N,M; cin>>N>>M;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			scanf("%1d", &maze[i][j]);
	queue<pair<int,int>> q;
	q.push(make_pair(1,1));
	maze[1][1] = 0;
	visCnt[1][1] = 1;
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		if(x == N && y == M){
			cout<<visCnt[N][M];
			exit(0);
		}
		q.pop();
		for(int i=0;i<4;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx<0 || nx>N ||ny<0 || ny>M) continue;
			if(!maze[nx][ny]||visCnt[nx][ny]) continue;
			q.push(make_pair(nx,ny));
			visCnt[nx][ny] = visCnt[x][y]+1;
			maze[nx][ny] =0;
		}
	}
	cout<<visCnt[N][M];
    return 0;
}
