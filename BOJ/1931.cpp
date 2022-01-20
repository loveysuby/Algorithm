#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
	fastio;
	
	int N; cin>>N;
	
	vector<pair<int,int>> v(N);
	/*빨리 끝날수록 먼저 시작해야됨(회의실 하나고 거기서 최대)
	모든 회의가 다 진행될 수 없다 == 특정 노드를 pass하는 조건 요구
	빨리끝나는순서로 정렬하고-> 시작시간 중 제일 빨리끝나는 시간보다 같거나큰거 넣어줄때마다 cnt++ (모든 회의를 탐색하고, 제빨끝시 이상 아닌건 패스)*/
	
	//first : 끝난시간 / sec: 시작시간
	for(int i=0;i<N;i++) 
		cin>>v[i].second>>v[i].first;
	
	//빨리 끝나는 것부터 먼저 반영하고(greedy) 
	//시작시간과 끝시간이 같은 경우 : 빨리끝나는대로 정렬, 끝나는 시간 같으면 빨리 시작하는거로 정렬
	sort(v.begin(),v.end());
	
	//현재 끝난 시간이 새거 시작시간보다 이하여야 함 => 현재끝난시간=새거끝난시간
	int ans = 0, tmp = 0;
	for(auto i : v){
		if(tmp <= i.second){
			ans++;
			tmp = i.first; //다음 회의 끝난시간(이게 다다음 회의 시작시간보다 이른지 재검)
		}
	}
	//처음 노드가 최적해가 될 수 없음? x (이후 노드가 어떤값이 올지 모르므로 일단 넣어야함)
	cout<<ans<<'\n';
}