//Header
#include <bits/stdc++.h>
//Define
using namespace std;

//Global elements
vector<int> vec;

//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	int cnt; cin>>cnt;
	for(int i=0;i<cnt;i++){
		int num; cin>>num;
		
		auto x = lower_bound(vec.begin(), vec.end(), num);
		if(x == vec.end())
			vec.push_back(num);
		else
			*x = num;	//greedy
	}
	cout<<vec.size();
	
    return 0;
}
