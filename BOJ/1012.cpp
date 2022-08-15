#include <bits/stdc++.h>
//Define
using namespace std;

//Global elements
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};	//상(0,1) 하(0,-1) 좌(-1,0) 우(1,0)
vector<vector<int>> vec(52,vector<int>(52));
//Function
void Solve(int nx, int ny){ //dfs
	vec[nx][ny] =0;
	for(int i=0;i<4;i++){
		if(vec[nx + dx[i]][ny + dy[i]]) //상하좌우 인접 좌표에 target 존재
			Solve(nx + dx[i],ny + dy[i]);
	}
}

//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);

	//N x M 행렬 =>  (1,1)~(m,n) : (기존의 0.0에서 좌표 이동 시 outofbounds -> row1, col1 모두 0으로 할당)
	int T;	
	cin>>T;	
	
	while(T--){
		int M, N, K, result =0;
		cin>>M>>N>>K;	
		
		while(K--){	
			int nx,ny;
			cin>>nx>>ny;
			vec[nx+1][ny+1] = 1;	
		}
		for(int i=1;i<=M;i++){
			for(int j=1;j<=N;j++){
				if(vec[i][j]){// case: target found
					Solve(i,j);
					result++;
				}
			}
		}	
		cout<<result<<'\n';
		fill(vec.begin(),vec.end(),vector<int>(52,0));		
	}	
    return 0;
}
