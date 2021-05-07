//Header
#include <iostream>
#include <vector>
//Define
using namespace std;

//Global elements
int res[10001] = {0};

//Function

//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	res[0]=1;
		
	int n,k;
	cin>>n>>k;
	int* coin = new int[n+1];	
	
	for(int i=1;i<=n;i++)
		cin>>coin[i];	
	for(int i =1;i<=n;i++){
		for(int j=coin[i];j<=k;j++)
			res[j]+= res[j-coin[i]];
	}
	
	delete[] coin;
	
	cout<<res[k];
	
    return 0;
}
