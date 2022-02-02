#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int a[3] = {300,60,10}, ac[3];
int main(){
	fastio;
	int T; cin>>T;
	if(T%10 != 0){
		cout<<-1; return 0;
	}
	for(int i=0; i<3 && T>0;i++){
		ac[i] = T/a[i];
		T %= a[i];
	}
	for(int i=0;i<3;i++)
		cout<<ac[i]<<' ';
}