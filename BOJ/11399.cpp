#include <bits/stdc++.h>
using namespace std;
//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	int N, sum = 0; cin>>N;
	vector<int> vec(N);
	for(int i =0;i<N;i++)
		cin>>vec[i];
	sort(vec.begin(),vec.end());
	for(int i =0;i<N;i++)
		sum += vec[i] * (N-i);	
	cout<<sum;
    return 0;
}