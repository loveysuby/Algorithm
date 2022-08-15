#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
	fastio;
	int N; cin>>N;
	int t5 = N/5, t3 = 0;
	while(1){
		if(t5<0){
			cout<<-1; return 0;
		}
		if((N-(5*t5)) % 3 == 0){
			t3 = (N-(5*t5)) / 3; break;
		}
		t5--;
	}
	cout<<t5+t3;
}