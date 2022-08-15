#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
	fastio;
	int H,M; cin>>H>>M;
	M -= 45; 
	if(M<0){
		M += 60; H--;
		if(H<0)
			H += 24;
	}
	cout<<H<<' '<<M;
}