//Header
#include <bits/stdc++.h>
//Define
using namespace std;
#define COL_MAX 1001
#define ROW_MAX 3
//Global elements
int arr[COL_MAX][ROW_MAX]={0};

//Function
void clear(){
	for(int i=0;i<3;i++)
		memset(arr,0,sizeof(int)*COL_MAX);
};
//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	int num; cin>>num;
	
	for(int i=1;i<=num;i++){
		for(int j=0;j<ROW_MAX;j++)
			cin>>arr[i][j];
	}
	for(int i=1;i<=num;i++){
		arr[i][0] += min(arr[i-1][1],arr[i-1][2]);
		arr[i][1] += min(arr[i-1][0],arr[i-1][2]);
		arr[i][2] += min(arr[i-1][0],arr[i-1][1]);
	}
	cout<<min(arr[num][0],min(arr[num][1],arr[num][2]));
    return 0;
}
