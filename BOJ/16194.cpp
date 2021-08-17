#include <bits/stdc++.h>
using namespace std;
vector<int> price(1001);
int dp[1001];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	int n; cin>>n;
	for(int i=1;i<=n;i++)
		cin>>price[i];
	for(int i =1;i<=n;i++){
		dp[i] = price[i];
		for(int j=1;j<=i;j++)
			dp[i] = min(dp[i],dp[i-j]+price[j]);
	}
	cout << dp[n];
    return 0;
}