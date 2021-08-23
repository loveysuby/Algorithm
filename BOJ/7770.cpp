#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N; cin>>N;
	int h=0, blocks=0;
	while(blocks<=N){
		blocks += (h+1)*(h+1) + h*h;
		h++;
	}
	cout<<h-1<<"\n";
	return 0;
}