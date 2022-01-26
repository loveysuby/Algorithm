#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int arr[10001];
int main(){
	fastio;
	int N; cin>>N;
	for(int i=0;i<N;i++){
		int elem; cin>>elem;
		arr[elem]++;
	};
	for(int i=1;i<10001;i++)
		for(int j=0;j<arr[i];j++)
			cout<<i<<'\n';
}