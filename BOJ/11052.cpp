//Header
#include <iostream>
#include <vector>
#include <algorithm>
//Define
#define ll long long

using namespace std;

//Global elements
vector<int> price(1001);
int dp[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>price[i];
	
	for(int i =1;i<=n;i++){
		for(int j=1;j<=i;j++){
			dp[i] = max(dp[i],dp[i-j]+price[j]);
		}			
	}
	
	cout << dp[n];

    return 0;
}