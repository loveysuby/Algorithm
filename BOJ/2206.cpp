#include <bits/stdc++.h>
// #include <iostream>
// #include <queue>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

//Global elements

//주의 : 변수 이름같은거 가급적 대문자로 하고, 자료구조 이름 아닌거 조심하기 ex)map  => (물론 map library를 빼면 해결되나, 아예 이런 방법은 지양)
//구조 안에 여러 개의 data를 집어 넣으려면 pair를 사용하거나, tuple을 사용하자
struct Node { int x,y, w; };
int maze[1001][1001], dist[1001][1001][2];
int dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
int N,M;

//Function
int bfs(){
	queue<Node> q;
	q.push({0,0,0});
	dist[0][0][0] = 1;
	
	while(!q.empty()){
		int x = q.front().x, y = q.front().y, wall = q.front().w;
		q.pop();
		
		//return point
		if(x == N-1 && y == M-1)
			return dist[x][y][wall];
		for(int i =0;i<4;i++){
			
			int nx = x + dx[i], ny = y + dy[i];
			//maze의 범위를 벗어나거나, 이미 지나간 기록이 잇어서 dist가 부여된 경우는 pass
			if(dist[nx][ny][wall] || nx<0||ny<0||nx>=N||ny>=M) continue;
			
			//wall ; 벽을 한번 뚫었는지 여부 , wall = 1인 노드가 푸시되면 안댐
			//maze.wall == 1 && wall = 0 로 분기해야 wall이 1로 바뀐 벽이 걸러짐
			
			//이웃 노드가 벽이 아닌 경우 -> dist++, 현재 뚫은상태 전달 wall push
			if(maze[nx][ny]==0){
				dist[nx][ny][wall] = dist[x][y][wall] + 1;
				q.push({nx,ny,wall});
			}
			//벽 만났는데 안 뚫린경우 => 뚫고(node.wall=1), 상태전달(앞으로안뜸)  
			else if(maze[nx][ny] ==1 && wall == 0){
				dist[nx][ny][wall+1] = dist[x][y][wall]+1;
				q.push({nx,ny,wall+1});
			}
		}
		
	}
	return -1;
}
//Driver
int main(){
	fastio;
	//숫자 1개씩 받으므로 이런 식으로 input 하면 안 됨
	
	// cin>>N>>M;
	// for(int i=0;i<N;i++){
	// 	for(int j=0;j<M;j++){
	// 		cin>>maze[i][j];
	// 		dist[i][j][0] = 0;
	// 		dist[i][j][1] = 0;
	// 	}
	// }
	
	scanf("%d %d", &N, &M);
	for (int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			scanf("%1d", &maze[i][j]);
	printf("%d\n", bfs());
}