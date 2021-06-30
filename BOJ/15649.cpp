#include <bits/stdc++.h>
//Define
using namespace std;

//Global elements
int N,M;
bool vis[10];
int arr[10];
//Function
void Solve(int curr){ //0
	if(curr == M){
		for(int i=0;i<M;i++) //arr[0] arr[1]
			cout<<arr[i]+1<<' ';
		cout<<'\n';
		return;
	}
	for(int i=0;i<N;i++){ // 1 2 3 4
		if(vis[i]) continue;
		vis[i] = true; //vis 1 = true -> arr(2,3,4)
		arr[curr]=i; // arr[0] =1;
		Solve(curr+1); // solve(1) -> arr[1] =2 => solve(2) -> arr[2] = 3
		vis[i] = false;
	}	
}
//Driver
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>N>>M;
	Solve(0);
    return 0;
}