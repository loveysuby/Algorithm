#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
	fastio;
	string s,res; cin>>s;
	stack<char> st;
	int pc = 0, sz = s.size(), flag;
	for(int i=0;i<sz;i++){
		if(s[i] == 'P')
			pc++; 
		// A가 들어왔는데 앞에 두글자 p고 다음글자 p인경우-> ppap==>p로 바꾸는 연산
		// A 이전에 P 개수 1개 줄이고 A 바로 뒤 P를 검사범위에서 skip -> p 1개로 인식
		else{
			if(pc>=2 && s[i+1] == 'P' && i < sz-1){
				pc--; i++;
			}
			else{
				cout<<"NP\n"; return 0;
			}
		}	
	}
	if(pc == 1) cout<<"PPAP\n";
	else cout<<"NP\n";
	return 0;
}