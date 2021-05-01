//Header
#include <iostream>
//Define
#define ll long long
using namespace std;

//Global elements

//Function

//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);	
	
	int count,n,m; cin >> count;
	
	while(count--){
		ll res = 1;
	
		cin>>n>>m;
		
		for(int i =1; i<=n;i++)
			res = res*(m-i+1)/i;
		
		cout<<res<<'\n';	
	}
    return 0;
}
