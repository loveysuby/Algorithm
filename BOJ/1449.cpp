#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 1001
int N, L, res;
int leak[MAX];
bool isTaped[MAX];

int main(){
	fastio;
	cin>>N>>L;
	for(int i=0;i<N;i++) cin>> leak[i];
	sort(leak,leak+N);
	for(int i=0;i<N;i++){
		if(!isTaped[leak[i]]){
			for(int j=leak[i];j<min(leak[i]+L, MAX);j++)
				isTaped[j] = true;
			res++;
		}
	}
	cout<<res<<'\n';
}