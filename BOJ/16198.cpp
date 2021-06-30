#include <bits/stdc++.h>
//Define
using namespace std;

//Global elements

int result_e;
//Function
void Solve(vector<int> marble, int curr_e){
	if(marble.size()==2) {
		result_e = max(result_e,curr_e);
		return;
	}
	for(int i=1;i<marble.size()-1;i++){
		vector<int> temp = marble;
		temp.erase(temp.begin()+i);
		Solve(temp, curr_e+marble[i-1]*marble[i+1]);
	}
}
//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	int size; cin>>size;
	vector<int> marble(size);
	for(int i=0;i<size;i++)
		cin>>marble[i];	
	
	Solve(marble,0);
	
	cout<<result_e;
	return 0;
}
