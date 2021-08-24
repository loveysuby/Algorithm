#include <bits/stdc++.h>
using namespace std;
//Global elements
int k,lotto[6], num[14];
//Function
void dfs(int idx, int cnt){
	if(cnt == 6){
		for(int i=0;i<6;i++)
			cout<<lotto[i]<<' ';
		cout<<'\n';
		return;
	}	
	for(int i = idx; i<k;i++){
		lotto[cnt] = num[i];
		dfs(i+1,cnt+1);
	}
}
//Driver
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while(cin>>k && k){
		for(int i = 0;i<k;i++)
			cin>>num[i];
		dfs(0,0);	
		cout<<'\n';
	}	
    return 0;
}