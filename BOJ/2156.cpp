//Header
#include <iostream>
#include <vector>
//#include <algorithm>

//Define
using namespace std;
//Function
int max(int x, int y, int z) { return x > y ? (x > z) ? x : z : (y > z) ? y : z; }
	
//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	int n; cin>>n;
	
	vector<int> value(n+1,0);
	vector<int> res(n+1,0);			//최대 시식량: res1 = val1 , res2 = val1 + val2 , ... 
	
	for(int i=1;i<=n;i++)
		cin>>value[i];
	
	res[1] = value[1];
	
	if( n >= 2) 
		res[2] = ( value[1] + value[2] );
	
	if (n>=3){
		res.push_back(value[1]+value[2]);
		for(int i=3;i<=n;i++){
			res[i] = max( value[i] + value[i-1] + res[i-3],			// ... XOO -> n-3 state 부터는 caching
							value[i] + res[i-2],					//   . .XO -> n-2 state 부터 ``
						 	res[i-1]);								//       X -> n-1 상태랑 같음
		}
	}
	
	cout << res[n];
	
	return 0;
}
