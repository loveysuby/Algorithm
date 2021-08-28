#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main()
{
    fastio;
	priority_queue<int> pq;
	int N; cin>>N;
	while(N--){
		int x; cin>>x;
		if(x) pq.push(x);
		else{
			if(!pq.empty()){
				cout<<pq.top()<<'\n';
				pq.pop();
			}
			else cout<<0<<'\n';
		}
	}
    return 0;
}