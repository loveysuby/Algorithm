#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//Global elements
vector<string> v;
char c[64][65] = {};
//Function
void solve(int x, int y, int size){
	char tmp = c[x][y];
	bool status = false;
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(c[x+i][y+j] != tmp){
				status = true;
				i = size; j = size;
			}
		}
	}
	if(!status) cout<<tmp;
	else{
		cout<<'(';
		solve(x,y,size/2);
		solve(x,y+size/2,size/2);
		solve(x+size/2,y,size/2);		
		solve(x+size/2,y+size/2,size/2);
		cout<<')';
	}
}
int main()
{
    fastio;
	int N; cin>>N;
	for(int i =0;i<N;i++) cin>>c[i];
	solve(0,0,N);
    return 0;
}