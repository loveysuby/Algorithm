#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

//Global elements
bool vis[10001];
queue<pair<int, string>> q;
string ans;
//Function
void push_tmp(int tmp, string str){
	if(!vis[tmp]){
		vis[tmp] = true;
		q.push(make_pair(tmp,ans+str));
	}
}
//Driver
int main()
{
	fastio;
	int N; cin>>N;	
	while(N--){
		int x, dest; cin>>x>>dest;	
		q.push(make_pair(x,""));
		while(!q.empty()){
			int n = q.front().first;
			ans = q.front().second;
			q.pop();
			if(n == dest) {
				cout<<ans<<'\n';
				break;
			}
			push_tmp((n*2) % 10000,"D");
			push_tmp(n == 0 ? 9999 : n-1,"S");
			push_tmp((n%1000)*10 + (n/1000),"L");
			push_tmp((n%10)*1000 + (n/10), "R");	
		}
		memset(vis,false,sizeof(vis));
		q = queue<pair<int,string>>();
	}
	return 0;
}

/*
//	D: D 는 n을 두 배로 바꾼다. 결과 값이 9999 보다 큰 경우에는 10000 으로 나눈 나머지를 취한다. 그 결과 값(2n mod 10000)을 레지스터에 저장한다.
			// push_tmp((n*2) % 10000 , "D");
			
			// tmp = (n*2) % 10000;
			// if(!vis[tmp]){
			// 	vis[tmp] = true;
			// 	q.push(make_pair(tmp,ans+"D"));
			// }
			push_tmp((n*2) % 10000,"D");
			
// 	S: S 는 n에서 1 을 뺀 결과 n-1을 레지스터에 저장한다. n이 0 이라면 9999 가 대신 레지스터에 저장된다.
			// tmp = n == 0 ? 9999 : n-1;
			// if(!vis[tmp]){
			// 	vis[tmp] = true;
			// 	q.push(make_pair(tmp,ans+"S"));
			// }
			push_tmp(n == 0 ? 9999 : n-1,"S");
			
// 	L 은 n의 각 자릿수를 왼편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d2, d3, d4, d1이 된다.
			// tmp = (n%1000)*10 + (n/1000);
			// if(!vis[tmp]){
			// 	vis[tmp] = true;
			// 	q.push(make_pair(tmp,ans+"L"));
			// }
			push_tmp((n%1000)*10 + (n/1000),"L");
			
// 	R 은 n의 각 자릿수를 오른편으로 회전시켜 그 결과를 레지스터에 저장한다. 이 연산이 끝나면 레지스터에 저장된 네 자릿수는 왼편부터 d4, d1, d2, d3이 된다
			// tmp = (n%10)*1000 + (n/10);
			// if(!vis[tmp]){
			// 	vis[tmp] = true;
			// 	q.push(make_pair(tmp,ans+"R"));
			// }
			push_tmp((n%10)*1000 + (n/10), "R");
*/