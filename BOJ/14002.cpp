#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main()
{
	fastio;
	
	int N; cin>>N;
	vector<int> input(N), len(N,1);
	vector<int> LIS[N];
	
	for(int i=0;i<N;i++) cin>>input[i];
	for(int i=0;i<N;i++) LIS[i].push_back(input[i]);
	
	for(int i=0;i<N;i++){
		for(int j=0;j<i;j++){
			if(input[j]<input[i] && len[i]<len[j]+1){
				len[i] = len[j]+1;
				LIS[i] = LIS[j];
				LIS[i].push_back(input[i]);
			}
		}		
	}
	int max_LIS_len = max_element(len.begin(),len.end())-len.begin();
	cout<<len[max_LIS_len]<<'\n';
	for(auto v : LIS[max_LIS_len])
		cout<<v<<' ';
}