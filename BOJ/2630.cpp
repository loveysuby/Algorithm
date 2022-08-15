#include <bits/stdc++.h>
//Define
using namespace std;

//Global elements
 
int arr[129][129]; 
int white, blue;
//Function
void dfs(int x,int y, int N){
	bool allZero, allOne;
	allZero = allOne = true;

	for(int i=x;i<x+N;i++){
		for(int j=y;j<y+N;j++){
			if(arr[i][j]==0) allOne = false;
			if(arr[i][j]==1) allZero = false;	
		}
	} //모두 1일때만 allone true; 둘 다 true인 경우 없음
	if(allZero) {
		white++;
		return;
	}
	if(allOne) {
		blue++;
		return;
	}

	dfs(x , y , N/2);
	dfs(x + N/2 , y , N/2);
	dfs(x , y + N/2, N/2);
	dfs(x + N/2, y + N/2, N/2);		
}

//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	int originSide; cin>>originSide;
	
	for(int i =0;i<originSide;i++){
		for(int j =0;j<originSide;j++)
			cin>>arr[i][j];
	}
	
	dfs(0,0,originSide);
	
	cout<<white<<'\n'<<blue;
    return 0;
}
