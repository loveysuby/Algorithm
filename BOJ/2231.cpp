#include <bits/stdc++.h>
//Define
using namespace std;

//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	int N; 
	cin>>N;
	
	for(int i=0;i<N;i++){
		int numSum = i;
		for(int tmp=i;tmp;tmp/=10) numSum += tmp%10;	
		if(numSum == N) {
			cout<<i;
			break;
		}
		if(i == N-1) 
			cout<<'0';
	}	
    return 0;
}
