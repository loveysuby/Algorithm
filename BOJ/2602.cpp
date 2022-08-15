#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

//Global elements
string key, load[2];
int dp[2][100][20];
//Function
int solve(int chk, int curr, int idx){
	if(idx == key.length()) 
		return 1;
	//memoization -> -1로 초기화 (0인 경우 존재)
	int& ans = dp[chk][curr][idx];
	if(ans != -1) return ans;	
	ans = 0;
    //curr부터 끝까지 돌리면서 타겟이랑 일치하는 경우 카운트 -> 번갈아가며 세면서 타겟 나올 때까지
	for(int i=curr;i<load[0].length();i++)
		if(load[chk][i] == key[idx])
			ans += solve(!chk, i+1, idx+1);
	return ans;
}
//Driver
int main()
{
	fastio;
	memset(dp,-1,sizeof(dp));
	cin>>key>>load[0]>>load[1];
	cout<< solve(0,0,0) + solve(1,0,0);
}