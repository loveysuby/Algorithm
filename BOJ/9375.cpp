#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main()
{
    fastio;
	int C; cin>>C;
	while(C--){
		int res = 1, N; cin>>N;
		map<string, int> m;
		while(N--){
			string x,y; cin>>x>>y;
			m[y]++;
		}
		for(auto curr = m.begin(); curr != m.end(); curr++)
			res *= curr->second + 1;
		cout<<res - 1<<'\n';
	}
}