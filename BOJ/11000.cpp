#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
	fastio;
	
	int N; cin>>N;
	
	vector<pair<int,int>> v(N);
	/*현재 가장 빠르게 끝나는 강의 (찾아야함)-> heap-max->pq max heap
	
	pq는 강의실이 돌아가고 있는 상태를 저장함(하나 늘때마다 강의실 하나씩 늘어나도록(계속 쓰는 강의실은 사용중인 상태므로, 상태가 유지되는 분기가 존재함 */
	priority_queue<int, vector<int>, greater<int>> pq;
	
	for(int i=0;i<N;i++) 
		cin>>v[i].first>>v[i].second;
	
	//빨리 시작하는 것부터 먼저 반영하고(greedy) 
	sort(v.begin(),v.end());
	
	//이후는 현재 끝난시간과 가장 가까운 것을 시작함
	pq.push(v[0].second);
	
	//현재 가장 빨리 끝난 시간이 다음 첫 강의 시작보다 이를 때-> 같은 강의실 공유-> pop+push(new.second)
	for(int i=1;i<N;i++){
		if(pq.top()<=v[i].first){
			pq.pop();
			pq.push(v[i].second);
		}
	//가장 빠른 강의가 현끝시보다 빠른 경우: 새로운 강의실(pop 생략,new node)
		else
			pq.push(v[i].second);
	}
	cout<<pq.size()<<'\n';
}