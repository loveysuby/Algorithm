#include <bits/stdc++.h>
using namespace std;
//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);	

	int N; cin>>N;
	vector<int> temp(N), res(N);
	for(int i=0;i<N;i++)
		cin>>res[i];
	temp = res;	
	sort(temp.begin(),temp.end());	
	temp.erase(unique(temp.begin(),temp.end()),temp.end());
	for(int i =0;i<N;i++){
		int x = lower_bound(temp.begin(),temp.end(),res[i])-temp.begin();
		cout<<x<<' ';
	}
    return 0;
}