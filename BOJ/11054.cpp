#include <bits/stdc++.h>
//Define
using namespace std;
#define MAX 1001
//Global elements
int arr[MAX];
int asc_len[MAX];
int desc_len[MAX];
//Function

//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	int N, result =0;
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>arr[i];
	
	for(int i = 0; i<N;i++){
		asc_len[i]=1;	
		for(int j=0;j<i;j++){
			if(arr[j]<arr[i]&&asc_len[i]<asc_len[j]+1)
				asc_len[i] = asc_len[j]+1;
		}
	}
	
	for(int i = N-1; i>=0;i--){
		desc_len[i]=1;	
		for(int j=N-1;j>i;j--){
			if(arr[j]<arr[i]&&desc_len[i]<desc_len[j]+1)
				desc_len[i] = desc_len[j]+1;
		}
	}
	
	for(int i=0;i<N;i++){
		if(result<asc_len[i]+desc_len[i])
			result = asc_len[i]+desc_len[i];
	}
	
	cout<<result-1;
	
    return 0;
}
