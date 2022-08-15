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
	
	int N; cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<=i;j++){
			cout<<'*';
		}
		cout<<"\n";
	}
    return 0;
}