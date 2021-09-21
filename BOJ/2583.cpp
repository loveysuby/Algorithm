#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

//Global elements
int N,M,K,res=0;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool board[101][101], vis[101][101];
vector<int> v;

//Function

/*
행렬의 x , y 좌표 인풋을 헷갈리는 것에 주의하자
arr[row][col] : row행 col열 / (y,x) 에 대응된다. 
행의 수 만큼 테이블의 높이가 높아지고 / 열의 수 만큼 테이블의 가로 길이가 길어진다.
*/
void find(int y, int x){
	res++;
	vis[y][x] = true;
	for(int i=0;i<4;i++){
		int nx = x + dx[i], ny = y + dy[i];
		if(nx<0||nx>=M||ny<0||ny>=N) continue;
		//미방문 + 영역에서 false 인 것이 해당 
		if(vis[ny][nx] || board[ny][nx]) continue; 
		find(ny,nx);
	}
}
//Driver
int main(){
	fastio;
	cin>>N>>M>>K; // 5 7 3
	
	for(int i=0;i<K;i++){
		int s1,s2,e1,e2; cin>>s1>>s2>>e1>>e2; // 0 2 4 4
		//영역에 해당되지 않는 곳을 결정한다
		for(int c = s1;c<e1;c++) // M
			for(int r = s2;r<e2;r++) // N 
				board[r][c] = true;	
	}
	//방문하지 않은 첫 영역부터 탐색을 시작하여 영역의 크기를 구한다
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(board[i][j] || vis[i][j]) continue;
			res = 0;
			find(i,j);
			v.push_back(res);
		}
		// !a && !b 0 0 ok 
		// !a || !b x -> 1 0 / 0 1 / 1 1 x 0 0 ok
		// a || b x - > 1 0 0 1 0 0 x 11 ok 
	}
	sort(v.begin(),v.end());
	cout<<v.size()<<'\n';
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<' ';
	cout<<'\n';
	return 0;
}