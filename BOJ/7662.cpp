#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pi pair<int,int>
int main(){
	fastio;
	int T; cin>>T;
	while(T--){
		int N; cin>>N;
		priority_queue<pi> maxq; // 최대값 추출
		priority_queue<pi, vector<pi>, greater<pi>> minq; // 최소값 추출 (오름차순)
		
		//최소/최대 두 개로 돌아가는데 상태 공유를 하기 위함
		bool isStored[1000001];
		
		for(int id=0;id<N;id++){
			char c; int num; 
			cin>>c>>num;
			if(c == 'I'){
				maxq.push(make_pair(num, id));
				minq.push(make_pair(num, id));
				isStored[id] = true;
			}
			else{ // delete
				if(num == 1){
					//이중 큐에 둘 중 하나라도 저장 안 된거 동기화
					while(!maxq.empty() &&!isStored[maxq.top().second])
						maxq.pop();
					if(!maxq.empty()){
						isStored[maxq.top().second] = false;
						maxq.pop();	
					}
				}else{ // num == -1
					while(!minq.empty() &&!isStored[minq.top().second])
						minq.pop();
					if(!minq.empty()){
						isStored[minq.top().second] = false;
						minq.pop();	
					}
				}
			}
		}
		while(!maxq.empty() &&!isStored[maxq.top().second])
			maxq.pop();
		while(!minq.empty() &&!isStored[minq.top().second])
			minq.pop();
		//result
		if(maxq.empty() || minq.empty()) 
			cout<<"EMPTY"<<"\n";
		else
			cout<<maxq.top().first<<' '<<minq.top().first<<'\n';	
	}
}