#include <bits/stdc++.h>
//Define
using namespace std;

//Global elements
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int arr[26][26];
int areaSize, component, componentArr[26*26]; //단지 당 요소의 수를 저장 : 단지 당 dfs연산이 되는 횟수
//Function
void dfs(int x,int y){
	arr[x][y]=0;
	componentArr[component]++;
	for(int i=0;i<4;i++){	
		if(x+dx[i]>=0 || x+dx[i] < areaSize || y+dy[i]>=0 ||y+dy[i] < areaSize)
			if(arr[x+dx[i]][y+dy[i]]==1)
				dfs(x+dx[i],y+dy[i]);
	}	
}

//Driver
int main()
{
	// ios::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);
	
 	cin>>areaSize;
	
	for(int i=1;i<=areaSize;i++)
		for(int j=1;j<=areaSize;j++)
			scanf("%1d", &arr[i][j]);
	
	for(int i=1;i<=areaSize;i++){
		for(int j=1;j<=areaSize;j++){
			if(arr[i][j]==1){
				dfs(i,j);
				component++;
			}
		}
	}
	
	sort(componentArr,componentArr+component);
	
	cout<<component<<'\n';
	for(int i=0;i<component;i++)
		cout<<componentArr[i]<<'\n';
		
	
    return 0;
}
