#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
string tmp[101][101];
string calc(string a, string b){
	int sum = 0; string res;
	while(!a.empty() || !b.empty() || sum){
		if(!a.empty()){
			sum += a.back()-'0'; // 맨끝 자리수 int변환
			a.pop_back();
		}
		if(!b.empty()){
			sum += b.back()-'0'; 
			b.pop_back();
		}
		res.push_back((sum%10)+'0'); //stringtify
		sum /= 10;
	}
	reverse(res.begin(),res.end());
	return res;
}
string comb(int n, int m){
	if(n==m || m==0) return "1";
	//caching
    string& res = tmp[n][m];
    
	if(res != "") return res;
    
	res = calc(comb(n-1,m-1),comb(n-1,m));
    
	return res;
}
int main(){
	fastio;
	int N,M; cin>>N>>M;
	cout<<comb(N,M);
}