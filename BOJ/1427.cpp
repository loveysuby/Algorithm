#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main(){
	fastio;
	string s; cin>>s;
	sort(s.begin(),s.end(),greater<>());
	cout<<s;
}