#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int N,res;
vector<bool> vis,isCycle;
vector<int> arr;

void dfs(int curr){
	vis[curr] = true;
	int next = arr[curr];
	if(!vis[next]) dfs(next);
    // if(vis[next] && !isCycle[next])..else dfs(next)
	/* 이 경우만 cycle
    ==> 코드만 보면 올바른 것처럼 보이나, 방문하였고 이미 사이클인 경우도 dfs 함수가
    돌아가는 조건에 포함됨
    (무한 루프 발생-> 함수 스택 메모리 초과) => 분기를 쪼개서 해결
    */
	else if(!isCycle[next]){	
		for(int tmp = next; tmp!=curr; tmp = arr[tmp])
			res++;
		res++; 
	}
	// else dfs(next);
	isCycle[curr] = true;	
}

int main(){
	fastio;
	int T; cin>>T;
	for(int i=0;i<T;i++){
		cin>>N;
		arr.resize(N+1);
		vis.assign(N+1,false);
		isCycle.assign(N+1,false);
		res = 0;
		for(int i=1;i<=N;i++)
			cin>>arr[i];
		for(int i=1;i<=N;i++)
			if(!vis[i]) dfs(i);
		cout<<N-res<<'\n';
	}
	return 0;
}