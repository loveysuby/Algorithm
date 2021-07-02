#include <bits/stdc++.h>
using namespace std;
//Define

//Global elements

//Function

//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	int a,b; cin>>a>>b;
	if(a>0 && b>0) cout<<"1";	
	else if(a<0 && b>0) cout<<"2";
	else if(a<0 && b<0) cout<<"3";
	else cout<<"4";
	
    return 0;
}