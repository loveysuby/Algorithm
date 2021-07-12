#include <bits/stdc++.h>
using namespace std;
//Global elements
int N,M,vip;
int res = 1, tmp = 0;
int dp[41]={1,1,};
//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);	
	cin>>N>>M;
	for(int i=2;i<=N;i++)
		dp[i] = dp[i-1]+dp[i-2];
	for(int i=0;i<M;i++){
		cin>>vip;
		res*=dp[vip-tmp-1];
		tmp=vip;
	}
	cout<<res*dp[N-tmp];
    return 0;
}