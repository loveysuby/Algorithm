#include <bits/stdc++.h>
using namespace std;
//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	int N,res=0; cin>>N;
	if(N==0){
		cout<<"0";
		return 0;
	}
	for(int i=5;i<=N;i++){
		if(i%5==0) res++;
		if(i%25==0) res++;
		if(i%125==0) res++;
	}
	cout<<res;
    return 0;
}