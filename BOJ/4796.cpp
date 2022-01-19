#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int L,P,V,ans,cnt=0;

int main(){
	fastio;
	while(1){
		cin>>L>>P>>V;
		if(!L&&!P&&!V) break;
		cnt++;
		ans = V/P * L;
		if(V%P<=L) ans += V%P;
		else
			ans += L;
		cout<<"Case "<<cnt<<": "<<ans<<'\n';
	}
}