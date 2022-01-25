#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
int main(){
	fastio;
	string s; cin>>s;
	sort(s.begin(),s.end(),greater<>());
	if(s[s.size()-1]!='0') {
		cout<<-1<<'\n';
		return 0;
	}
	//맨끝이 0 -> 모든 자리수 합 3의 배수면 s: 30 배수
	else{
		ll sum = 0;
		
		for(auto c : s)
			sum += c-'0';
		
		if(sum % 3 == 0)
			cout<<s<<'\n';
		else
			cout<<-1;
	}
}