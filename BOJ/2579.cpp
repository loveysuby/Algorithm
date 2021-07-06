#include <bits/stdc++.h>
using namespace std;
//Global elements
int arr[301];
int dp[301];
//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	int N; cin>>N;
	for(int i=1;i<=N;i++)
		cin>>arr[i];	
	dp[1] = arr[1];	
	for(int i = 2; i<= N;i++)
		dp[i] = max(arr[i-1]+dp[i-3],dp[i-2]) + arr[i];	
	cout<<dp[N];
	return 0;
}
