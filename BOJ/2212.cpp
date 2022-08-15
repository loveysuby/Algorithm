#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
	fastio;
	int N,K; cin>>N>>K;
	vector<int> v(N),d(N);
	
	for(int i=0;i<N;i++) cin>>v[i];//136679
	sort(v.begin(),v.end());
	
	// v.erase(unique(v.begin(),v.end()),v.end());//13679	5
	// 이거 중복있는거 없는 거 구분해야 될 줄 알았는데, N개로 정해져 있는 거에서 K가 할당되는 개수가 정해져있어서 할 필요 없음
	// int maxDist = v[N-1] - v[0]; // 8 = dist.sum; ==> bottom-up으로 큰거부터 빼려고 했는데 sort 내림차순 해야되서 pass
	
	for(int i=0;i<N-1;i++)
		d[i] = v[i+1] - v[i]; //2312  4 	9
	
	sort(d.begin(),d.end());//1223 4	4-2 = 2 012		9 - 5 = 4 01234 
	//i < v-size - k/ 4 - 2 -1 1
	int res = 0;
// 	N개 노드가 있으면 N-1개 거리값이 생김 -> 거기서 짧은 순으로 N-(K-1)개 더해주면 그 거리에 맞는 구간합으로 최적해를 도출함
// 	노드가 2개 이상 묶일 수 있으므로, N-(K-1)개 매칭된 값이 K보다 많으면 두 거리값을 더해서 하나의 구간으로 합치면 됨
	for(int i=0;i<N-K+1;i++){
		// cout<<d[i]<<endl;
		res += d[i];
	}
		
	cout<<res;
// 	left right 범위 좁혀가면서 거리 짧은 곳을 node로 박고 개수를 줄여나가려고 함
// 	node와 sensor 위치가 같은 분기에서 res를 어떻게 갱신할까?
//  그냥 sort 하면 해결됨

}