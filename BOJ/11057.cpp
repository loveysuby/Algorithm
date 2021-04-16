//Header
#include <iostream>
//Define
#define ll long long
#define mod 10007
using namespace std;

//Global elements

//dp[i][j] : i자리 숫자에서 1의자리가 j인 case의 오르막 수 
//ex: dp[3][4] : xx4 꼴 . -> dp(2.0)부터 dp(2.4) 까지 앞의 두 자리(xx부분)에 올 수 있음. => 수식화
int dp[1001][10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	
	int sum = 0, res = 0;
	ll n;
	
	cin >> n;
	
	for(int i=0;i<=9;i++)
		dp[1][i]=1;
	
	for(int i =2;i<=n;i++){
		for(int j=0;j<=9;j++){
			for(int k=0;k<=j;k++){
				dp[i][j] += dp[i-1][k];
				dp[i][j] %= mod;
			}				
		}
	}
	
	for(int i=0;i<=9;i++)
		sum += dp[n][i];
	
	cout<<sum % mod<<'\n';	
		
    return 0;
}