#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//Global elements
int arr[1001];
int ans[1001];
//Driver
int main()
{
	fastio;
	int C, res = 0; cin>>C;
	for(int i=0;i<C;i++){
		cin>>arr[i];
		ans[i] = arr[i];
		for(int j=0;j<=i;j++){
			if(arr[j]<arr[i] && ans[i] < ans[j] + arr[i])
				ans[i] = ans[j] + arr[i];
			res = max(res,ans[i]);
		}
	}
	cout<<res;
	return 0;
}