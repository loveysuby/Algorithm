//Header
#include <iostream>
#include <algorithm>
//Define
using namespace std;

//Global elements
int arr[1001];
int length[1001];

int binary(int left, int right, int target){
	int mid = left + right / 2;
	while(left<right){
		
	}
	if(mid < target){
		left = mid + 1;
		return binary(left,right,target);
	}
	else
		right = mid;
	return right;	
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n;
	cin >> n;	
	for(int i = 0; i<n;i++)
		cin>>arr[i];
	
	
    return 0;
}