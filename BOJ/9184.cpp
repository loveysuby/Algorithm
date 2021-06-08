//Header
#include <bits/stdc++.h>
//Define
using namespace std;

//Global elements
const int MAX = 21;
int dp[MAX][MAX][MAX];
int a,b,c;
//Function
int w(int a, int b, int c){
	if(a<=0||b<=0||c<=0)
		return 1;
	if(a>=MAX||b>=MAX||c>=MAX)
		return w(20,20,20);
	
	int &res = dp[a][b][c];
	
	if(res != 0)
		return res;
	
	if(a<b && b<c)
		res = w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c);
	else
		res = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
	return res;
}

//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);

	while(true){
		cin>>a>>b>>c;
		if(a==-1&&b==-1&&c==-1)
			break;
		cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<w(a,b,c)<<'\n';
	}
    return 0;
}