#include <bits/stdc++.h>
//Define
using namespace std;

//Global elements
int N, result;
int arr[9];
bool vis[9];
vector<int> v;
//Function / brute-force : 모든 순열을 생성 -> 계산
void dfs(int curr){
	if(curr == N){
		int sum = 0;
		for(int i=0;i<v.size()-1;i++)
			sum += abs(v[i]-v[i+1]);
		result = max(result, sum);
		return;
	}	
	for(int i=0;i<N;i++){ //순열 생성 : 조합과 달리 순서다른 중복가능. loop에서 vis 체크하지 않고 vec에 따로 저장해서 base case 유발.
		if(vis[i]) continue;
		vis[i] = true;
		v.push_back(arr[i]);
		dfs(curr+1);
		vis[i] = false;	
		v.pop_back();
	}
}
//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>N;
	for(int i=0;i<N;i++) cin>>arr[i];
	dfs(0);
	cout<<result;
	
    return 0;
}