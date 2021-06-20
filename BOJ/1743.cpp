#include <bits/stdc++.h>
//Define
using namespace std;

//Global elements
int mat[101][101];
bool vis[101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int N,M,K, component = 0;

//Function
void Solve(int x,int y){
	for(int i=0;i<4;i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx<=0 && ny <=0 && nx>N && ny>M) continue;
		if(!vis[nx][ny]&&mat[nx][ny]==1){
			component++;
			vis[nx][ny] = true;
			Solve(nx,ny);
		}
	}
}

//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);	
	
	int result = 0;
	cin>>N>>M>>K;
	for(int i=0;i<K;i++){
		int n1,n2; cin>>n1>>n2;
		mat[n1-1][n2-1] =1;
	}	
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(!vis[i][j]&&mat[i][j]==1){
				component=0;
				Solve(i,j);
				result = max(result,component);
			}
		}
	}
	cout<<result;
	return 0;
}
