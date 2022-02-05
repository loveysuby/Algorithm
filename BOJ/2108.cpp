#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
vector<double> v;
int N, cnt[8001];
double mode, avg = 0;
int main(){
	fastio;
	cin>>N;
	for(int i=0;i<N;i++) {
		int tmp; cin>>tmp;
		v.push_back(tmp);
		cnt[tmp+4000]++;
		avg += tmp;
	}
	sort(v.begin(),v.end());
	int T=0, tmode = *max_element(cnt, cnt+8001);
	for(int i=0;i<8001;i++){
		if(T==2) break;
		if(cnt[i] == tmode) {
			mode = i;
			T++;
		}
	}
	cout<<round((double)(avg / N))<<'\n';
	cout<<v[N/2]<<'\n';
	cout<<mode-4000<<'\n';
	cout<<v.back()-v.front()<<'\n';
}