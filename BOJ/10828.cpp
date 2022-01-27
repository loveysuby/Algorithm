#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
	fastio;
	int N; cin>>N;
	stack<int> st;
	string s;
	for(int i=0;i<N;i++) {
		cin>>s;
		if(s == "push"){
			int tmp; cin>>tmp;
			st.push(tmp);
		}else if(s == "pop"){
			if(st.empty()) 
				cout<<-1<<'\n';
			else{
				cout<<st.top()<<'\n';
				st.pop();
			}
		}else if(s == "size"){
			cout<<st.size()<<'\n';
		}else if(s == "empty"){
			if(st.empty())
				cout<<1<<'\n';
			else
				cout<<0<<'\n';
		}else if(s == "top"){
			if(st.empty()) 
				cout<<-1<<'\n';
			else
				cout<<st.top()<<'\n';
		}
	}	
}