//Header
#include <bits/stdc++.h>
//Define
using namespace std;
#define MOD 9901
//Global elements
int arr[100001] = {1,3,7,};

//Function
int Solve(int num){
	for(int i=3;i<=num;i++)
		arr[i] = (arr[i-1]*2+arr[i-2])% MOD;	//MOD 연산은 배열에 넣어주는 과정에서 해야 overflow가 발생하지 않는다
	return arr[num];
}
//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	int x; cin>>x;
	
	cout<<Solve(x);
	
    return 0;
}
