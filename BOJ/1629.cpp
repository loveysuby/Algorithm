#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int a,b,c;
int solve(int x, int y){
	if(y==0) return 1;
	int N = solve(x,y/2);
	int res = (1ll * N * N) % c;
	if(y%2) res = (1ll * res * x) % c;
	return res;
}
int main(){
	fastio;
	cin>>a>>b>>c;
	cout<<solve(a,b);
}