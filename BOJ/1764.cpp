#include <bits/stdc++.h>
using namespace std;
//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	vector<string> vec;
	vector<string> vec_res;
	int N,M; cin>>N>>M;
	
	vec.resize(N+M+1);
	for(int i=0;i<N+M;i++)
		cin>>vec[i];
	sort(vec.begin(),vec.end());
	
	for(int j=1;j<=N+M;j++){
		if(vec[j]==vec[j-1])
			vec_res.push_back(vec[j]);
	}
	
	cout<<vec_res.size()<<'\n';	
	for(int k=0;k<vec_res.size();k++)
		cout<<vec_res[k]<<'\n';	
    return 0;
}