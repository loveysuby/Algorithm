#include <bits/stdc++.h>
using namespace std;
//Define

//Global elements
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int arr[1001][1001];
int day[1001][1001];
//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	int M, N, result = 0; cin>>M>>N;
	queue<pair<int,int>> q;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>arr[i][j];
			day[i][j] = -1;
			if(arr[i][j] == 1){
				q.push(make_pair(i,j));
				day[i][j]=0;
			}	
		}
	}
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i =0;i<4;i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx<0||nx>=N||ny<0||ny>=M) continue;
			if(arr[nx][ny]==0&&day[nx][ny]==-1){
				q.push(make_pair(nx,ny));	
				day[nx][ny] = day[x][y]+1;
				arr[nx][ny] =1;
			}	
		}	
	}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(arr[i][j]==0&&day[i][j]==-1){
				cout<<"-1";
				return 0;
			}
			if(result<day[i][j]) result = day[i][j];
		}
	}
	cout<<result;
	
    return 0;
}