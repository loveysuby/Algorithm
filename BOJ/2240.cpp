#include <bits/stdc++.h>
using namespace std;
//Global elements
int dp[1001][31][2];
int plum[1001];
//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	int T,W,res=0; cin>>T>>W;	
	for(int i=1;i<=T;i++)
		cin>>plum[i];
	dp[0][0][0] = 0;
	dp[0][0][1] = 0;
	for(int i=1;i<=T;i++){
		dp[i][0][0] = dp[i-1][0][0]+(plum[i]==1);
		for(int j=0;j<=W;j++){
			if(i<j) continue;	//현재 시간보다 움직인 횟수가 많을 수 없음
			if(j%2==0)			//짝수번 움직인 경우 -> 무조건 원래자리임
				dp[i][j][0] = max(dp[i-1][j][0],dp[i-1][j-1][1])+(plum[i]==1);
			else				//max(1초 전에 이동 안하고 그대로 받았을때 , 자두 받고 자리 이동할때)+현재자리 자두 있으면 받기
				dp[i][j][1] = max(dp[i-1][j][1],dp[i-1][j-1][0])+(plum[i]==2);
		}
	}
    for(int i=0;i<=W;i++){
		res = max(res, dp[T][i][0]);
        res = max(res, dp[T][i][1]);        
    }
	cout<<res;
    return 0;
}