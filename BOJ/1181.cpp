#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
bool cmp(string a, string b){
	if(a.length() == b.length()){
		return a<b;
	}
	return a.length() < b.length();
}
int main(){
	fastio;
	int N; cin>>N;
	
	vector<string> v(N);
	
	for(int i=0;i<N;i++)
		cin>>v[i];
	
	sort(v.begin(),v.end(),cmp);
	
	v.erase(unique(v.begin(),v.end()),v.end());
	
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<endl;
}