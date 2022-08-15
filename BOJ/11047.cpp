#include <bits/stdc++.h>
using namespace std;
//Global elements
int arr[11];
//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	int N,K,result =0; cin>>N>>K;
	for(int i=0;i<N;i++)
		cin>>arr[i];
	for(int i=1;i<=N;i++){
		result += K/arr[N-i];
		K %= arr[N-i];
		if(K <= 0) break;	
	}
	cout<<result;	
    return 0;
}