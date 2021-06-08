//Header
#include <bits/stdc++.h>
//Define
using namespace std;

//Global elements


//Function
bool isPrime(int x){
	if(x<2) return false;
	
	for(int i=2;i*i<=x;i++)
		if(x% i == 0){ return false;}
	
	return true;
}

//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	int count, num, result=0;
	cin>>count;
	
	while(count--){
		cin>>num;
		if(isPrime(num)) result++;		
	}
	cout<<result;
    return 0;
}
