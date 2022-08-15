//Header
#include <iostream>
#include <algorithm>
//Define
using namespace std;

//Global elements
int arr[1001];
int length[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n;
	cin >> n;
		
	for(int i = 0; i<n;i++){
		int num;
		cin>>num;
		arr[i] = num;	
	}
	
	for(int i = 0; i<n;i++){
		length[i]=1;
		//arr[j]<arr[i](앞의 수보다 더 큰 수 발견한 경우)->증가수열이므로 length++
		for(int j=0;j<i;j++){
			if(arr[j]<arr[i])
				length[i] = max(length[i],length[j]+1);
		}
	}
	
	cout<< *max_element(length,length+n) <<'\n';
	
    return 0;
}