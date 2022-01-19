#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define QCNT 11

vector<pair<int,int>> v(QCNT); 
int main(){
	fastio;
	int time=0, penalty=0;
	
	for(int i=0;i<QCNT;i++)
		cin>>v[i].first>>v[i].second;
	
	sort(v.begin(),v.end()); //time 기준으로 오름차순 
	/*
	어차피 v.second(error)는 문제 순서 상관없이 개당 20이고
	빨리 풀 수 있는 거부터 푸는게 시간 합산 점수에서 이득이므로
	패널티에서 에러 있는 것마다 20점씩 얹어주면서 한 번만 돌면 가능	
	*/
	for(int i=0;i<QCNT;i++){
		time += v[i].first;
		penalty += (time + 20*v[i].second);
	}
	
	cout<<penalty<<'\n';
}