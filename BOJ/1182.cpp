//Header
#include <bits/stdc++.h>
//Define
using namespace std;

//Global elements
int numArr[100001];
int dp[100001];

//Function


//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);

	int N, result; cin>>N;	
	
	for(int i =0;i<N;i++)
		cin>>numArr[i];
	
	result = dp[0] = numArr[0];
	
	for(int i=1;i<N;i++){
		dp[i] = max(numArr[i], dp[i-1]+numArr[i]);
		if(result<dp[i]) result = dp[i];
	}
	cout<<result;
	
    return 0;
}
