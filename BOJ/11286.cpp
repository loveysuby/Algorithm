#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
struct cmp{
	bool operator()(int x, int y){
		if(abs(x)==abs(y)) return x>y;
		return abs(x)>abs(y);
	}
};
int main()
{
    fastio;
	int N,elem; cin>>N;
	priority_queue<int, vector<int>, cmp> pq;
	while(N--){
		cin>>elem;
		if(elem) pq.push(elem);
		else{
			if(pq.empty())
				cout<<0<<'\n';
			else{
				cout<<pq.top()<<'\n';
				pq.pop();
			}
		}
	}
    return 0;
}