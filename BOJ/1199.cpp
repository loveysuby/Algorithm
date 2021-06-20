#include <bits/stdc++.h>
//Define
using namespace std;

//Global elements
int N, nodes[1010];
int adj[1010][1010];
//Function
void Solve(int curr){
	for(int &i=nodes[curr];i<=N;i++){
		while(adj[curr][i]){
			adj[i][curr]--;
			adj[curr][i]--;
			Solve(i);
		}
	}
	cout<<curr<<' ';
}
//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>N;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			cin>>adj[i][j];
	
	for(int i=1;i<=N;i++){
		int sum = 0;
		for(int j=1;j<=N;j++)
			sum+= adj[i][j];
		if(sum%2) 
			return !printf("-1");
	}
	for(int i=1;i<=N;i++)
		nodes[i]=1;	
	Solve(N);
    return 0;
}
