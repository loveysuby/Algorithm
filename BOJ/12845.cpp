#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
bool cmp(int a, int b){
	return a>b;
}
vector<int> v;
int main(){
	fastio;
	int N; cin>>N;
	
	v.resize(N);
	
	for(int i=0;i<N;i++)
		cin>>v[i];	
	//제일 고렙 카드가 모든 카드와 합성하게 되므로 순서 고려않고 내림차순 소트한 뒤에 누적합 구하면 최대 합성값 도출 가능
	sort(v.begin(),v.end(),cmp);
	
	int sum = 0;
	
	for(int i=1;i<N;i++)
		sum += v[i] + v[0];
	
	cout<<sum;
}