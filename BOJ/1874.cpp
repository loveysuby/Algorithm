#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
	fastio;
	int N; cin>>N;
	int order[N]; 
	stack<int> st;
	vector<char> res;
	for(int i=0;i<N;i++)
		cin>>order[i];
	int curr = 0;
	for(int i=1;i<=N;i++){
// 		1부터 스택 차례로 채우다가
		st.push(i);
		res.push_back('+');
// 		비어있지 않은 스택에 현재 i값이 수열의 값(order[curr])이어야 하는 경우, i만큼 pop하고 char mapping -> curr++
		while(!st.empty() && st.top() == order[curr]){
			curr++; st.pop();
			res.push_back('-');
		}	
	}
	if(!st.empty()) 
		cout<<"NO"<<'\n';
	else 
		for(auto r : res) cout<<r<<'\n';
}