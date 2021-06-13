//Header
#include <bits/stdc++.h>
//Define
using namespace std;

//Global elements
int arr[20];
int N,S,result;
//Function
void dfs(int idx, int sum){
	sum += arr[idx];
	
	if(idx >= N) return;
	if(sum == S) result++;
	
	dfs(idx+1, sum-arr[idx]); // not added arr[idx] to sum this scope
	dfs(idx+1, sum);
}

//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
		
	cin>>N>>S;
	
	for(int i=0;i<N;i++)	cin>>arr[i];
	
	dfs(0,0);	
	
	cout<<result;
	
	return 0;
}
