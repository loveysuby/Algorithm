#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//Global elements
int N, ans = 2147483647, stat[21][21];
bool check[21];
//Function
void dfs(int idx, int size){
	if(size == N/2){
		int start = 0, link = 0;
		for(int i = 1; i<=N; i++){
			for(int j = 1; j<=N; j++){
				if(check[i] && check[j]) start += stat[i][j];
				if(!check[i] && !check[j]) link += stat[i][j];
			}
		}
		if(ans>abs(start - link))
			ans = abs(start - link);
		return;
	}
	for(int i = idx; i<N;i++){
		check[i] = true;
		dfs(i+1, size+1);
		check[i] = false;
	}
}
int main()
{
    fastio;
	cin>>N;
	for(int i = 1; i<=N; i++)
		for(int j = 1; j<=N; j++)
			cin>>stat[i][j];
	dfs(1,0);
	cout<<ans;
    return 0;
}