#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
	fastio;
	int N; cin>>N;
	vector<int> v(N);
	for(int i=0;i<N;i++) cin>>v[i];
// 	제일 성능 구린 로프 * 3부터 시작
	sort(v.begin(),v.end());
	int tmp = 0;
	for(int i=0;i<N;i++){
		int c = (N - i) * v[i];
		if(tmp<c) tmp = c;
	}
	cout<<tmp;
}