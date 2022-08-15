//Header
#include <iostream>
#include <vector>
#include <algorithm>
//Define
using namespace std;

//Global elements

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	int n, res =0; 
	cin>>n;
		
	vector<vector<int>> dp(n+1 , vector<int>(n+1,0));
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cin>>dp[i][j];
			dp[i][j] += max(dp[i-1][j-1],dp[i-1][j]);
			if(i==n)
				res = max(res, dp[i][j]);
		}
	}	
	cout << res;
    return 0;
}