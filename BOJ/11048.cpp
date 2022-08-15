#include <bits/stdc++.h>
using namespace std;

//Global elements
int maze[1001][1001];
//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	int N,M; cin>>N>>M;
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M; j++){
			cin>>maze[i][j];
			maze[i][j] += max(maze[i-1][j],maze[i][j-1]);	
		}
	}
	cout<<maze[N][M];
    return 0;
}