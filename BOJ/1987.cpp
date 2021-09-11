#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

//Global elements
int R,C;
int arr[21][21], dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
bool vis[23];

//Function
int solve(int x, int y){
	int block = 0, curr = arr[x][y];
	vis[curr] = true;
	//dfs 박음 -> continue 처리할때 or 역연산 빠른 도출 요구됨
	for(int i=0;i<4;i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		//backtracking : vis 존재여부보다 탐색 유효 범위를 먼저 확인해야함. 무효 노드는 null로 접근되어 오류 여지 존재함
		if(nx<0 || ny<0 || nx>=R || ny>=C || vis[arr[nx][ny]]) continue;
		block = max(block, solve(nx,ny));
	}
	//상태 초기화를 해야 다음 탐색에서 미방문 상태로 다시 돌아감
	vis[curr] = false;
	
	return block+1;
}
//Driver
int main()
{
	fastio;
	cin>>R>>C;
	for(int i=0;i<R;i++){
		string s; cin>>s;
		for(int j=0;j<C;j++)
			//문자로 넣으면 vis연산에서 idx찾기가 너무 복잡해졌었다. 숫자로 돌려막았는데 훨씬 편함
			arr[i][j] = s[j] - 'A';
	}
	cout<<solve(0,0)<<'\n';
	return 0;
}