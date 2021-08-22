#include <bits/stdc++.h>
using namespace std;
int N,M;
vector<int> v;
void comp(int idx,int cnt){
	if(cnt == M){
		for(int i = 0; i<M;i++)
			cout<<v[i]+1<<' ';
		cout<<'\n';
		return;
	}
	for(int i = idx; i<N; i++){
		v.push_back(i);
		comp(i+1,cnt+1);
		v.pop_back();
	}
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>N>>M;
	comp(0,0);
    return 0;
}