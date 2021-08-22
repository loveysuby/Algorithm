#include <bits/stdc++.h>
using namespace std;
//Global elements
int N, ans=1;
string arr[51];
//Function
int getRes(){
	int res = 1;
	for(int i =0; i<N;i++){
		int tmp = 1;
		for(int j = 1;j<N;j++){
			if(arr[i][j-1]==arr[i][j]) tmp++;
			else{
				res = max(res,tmp);
				tmp = 1;
			}
		}
		res = max(res,tmp);
	}
	for(int i =0; i<N;i++){
		int tmp = 1;
		for(int j = 0;j<N-1;j++){
			if(arr[j][i]==arr[j+1][i]) tmp++;
			else{
				res = max(res,tmp);
				tmp = 1;
			}
		}
		res = max(res,tmp);
	}
	return res;
}
void solve(){
	for(int i = 0;i<N;i++){
		for(int j = 0;j<N-1;j++){
			swap(arr[i][j],arr[i][j+1]);
			ans = max(ans,getRes());
			swap(arr[i][j],arr[i][j+1]);
			swap(arr[j][i],arr[j+1][i]);
			ans = max(ans,getRes());
			swap(arr[j][i],arr[j+1][i]);
		}
	}	
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>arr[i];
	solve();
	cout<<ans;	
    return 0;
}