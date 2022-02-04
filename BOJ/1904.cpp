#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
	fastio;
	int N;cin>>N;
	int v[1000001]={0,1,2};
	for(int i=3;i<=N;i++)
		v[i]=(v[i-2]+v[i-1])%15746;
	cout<<v[N];
}