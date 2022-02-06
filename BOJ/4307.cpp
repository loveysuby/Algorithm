#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int S,N;
int main(){
	fastio;
	int T; cin>>T;
	while(T--){
		cin>>S>>N;
		int F=0,L=0;
		//개미가 마주치는 케이스 고려 안해도 됨(업고 감)
		//0이나 끝으로 도달하는 시간 중 짧은 것들(최소 도달시간) 중 최대값 = 모든 노드 처리되는 시간
		// `` 최대 도달시간 중 최대값 = 모든 노드가 처리되는 최대값
		for(int i=0;i<N;i++){
			int p; cin>>p;
			int tf = min(p,S-p), tl = max(p,S-p);
			F = max(F,tf); L = max(L,tl);
		}
		cout<<F<<' '<<L<<'\n';
	}
}