#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//Global elements
int num, N;
priority_queue<int, vector<int>, less<int> > m_pq;
priority_queue<int, vector<int>, greater<int> > l_pq;
//Driver
int main()
{
    fastio;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>num;
		if(m_pq.empty()) m_pq.push(num);
		else{
			if(m_pq.size() > l_pq.size())
				l_pq.push(num);
			else
				m_pq.push(num);
			if(m_pq.top() > l_pq.top()){
				int tmp1 = m_pq.top(), tmp2 = l_pq.top();
				m_pq.pop(); l_pq.pop();
				m_pq.push(tmp2); l_pq.push(tmp1);
			}
		}
		cout<<m_pq.top()<<'\n';
	}
    return 0;
}