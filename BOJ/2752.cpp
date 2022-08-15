#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
	fastio;
	vector<int> v(3);
	for(int i=0;i<3;i++)cin>>v[i];
	sort(v.begin(),v.end());
	for(int i=0;i<3;i++){cout<<v[i]<<' ';}
	
}