#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main()
{
    fastio;
	int N,K,temp = 0; cin>>N>>K;
	queue<int> q;
	cout<<'<';
	for(int i=1;i<=N;i++)
		q.push(i);
	while(q.size()>1){
		for(int i=0;i<K-1;i++){
			q.push(q.front()); q.pop();
		}	
		cout<<q.front()<<", ";
		q.pop();
	}
	cout<<q.front()<<'>';
    return 0;
}