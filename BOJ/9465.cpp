#include <bits/stdc++.h>
//Define
using namespace std;

//Global elements
int N;
int point[2][100001];
int score[2][100001];
//Function

//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	int T; cin>>T;
	while(T--){
		cin>>N;	
		memset(point,0, sizeof(point));
		memset(score,0, sizeof(score));
		
		for(int i=0;i<2;i++){
			for(int j=1;j<=N;j++)
				cin>>point[i][j];
		}	
		score[0][1] = point[0][1];
		score[1][1] = point[1][1];	
		for(int idx = 2; idx <= N; idx++){
			score[0][idx] = max(score[1][idx-1],score[1][idx-2]) + point[0][idx];
			score[1][idx] = max(score[0][idx-1],score[0][idx-2]) + point[1][idx];
		}	
		cout<<max(score[0][N],score[1][N])<<'\n';
	}	
    return 0;
}