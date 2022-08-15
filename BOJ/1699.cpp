#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int dp[100001];
	int N;
	cin>>N;
	for(int idx=0;idx<=N;idx++)	dp[idx] = idx;	
	for(int i=4;i<=N;i++)
		for(int j=2;j*j<=i;j++)
			dp[i] = min(dp[i],dp[i-j*j]+1);
	cout<<dp[N];
    return 0;
}
