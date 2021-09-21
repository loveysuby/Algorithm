#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
/*
10 1 10 2 1 
f  s  g u d   ========? 6

10층 목표는 10층 현재는 1층 u는 +2층 d는 -1 층 --> 최소 횟수는6번 ( 최소파악 x)

1 + 2 2 2 2 - 1 + 2 = 10 

1에서 0으로 갈 수는 없다. (exception)
s (u, d)
u->(u,d) 
sol : 큐에 curr + U , curr - D 넣고 돌리다가 타겟 나오면 출력,
모든 노드의 범위는 (0,F], level은 -1로 초기화 후 양수 노드를 가질 때만 큐에 넣는다
*/
//Global elements
int F,S,G,U,D;
int level[1000001];

//Function
void solve(){
	queue<int> q;
	q.push(S); level[S] = 0;
	while(!q.empty()){
		int x = q.front(); q.pop();
		if(x == G){
			cout<<level[x]<<'\n';
			return;
		}
		// int up = x + U, down = x - D;
		for(int mv : {x+U,x-D}){
			if(mv<1||mv>F||level[mv]>-1) continue;
			q.push(mv);
			level[mv] = level[x]+1;
		}
	}
	//큐에 다 넣고 돌렸는데도 못 찾은 경우
	cout<<"use the stairs\n";
	return;
}
//Driver
int main(){
	fastio;
	cin>>F>>S>>G>>U>>D;
	memset(level,-1,sizeof(level));
	solve();
}