#include <bits/stdc++.h>
using namespace std;
//Global elements
int arr[2188][2188];
int result[3];
//Function
void Solve(int x, int y, int size){
	bool notPaper = false;
	int temp = arr[x][y];
	for(int i=x;i<x+size;i++){
		for(int j=y; j<y+size;j++){
			if(arr[i][j]!=temp){ //범위 내의 모든 요소가 같지 않음 -> case: not paper
				notPaper = true;
				i=x+size,j=y+size; //break loop
			}	
		}
	}
	if(!notPaper) result[temp+1]++;
	else{
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				Solve(x+i*size/3,y+j*size/3,size/3);
	}
	//이것도 되는데 변수 줄일 수 있었음
	// bool chk_0=true,chk_minus1=true,chk_plus1=true;
	// for(int i=x;i<x+size;i++){
	// 	for(int j=y; j<y+size;j++){
	// 		if(arr[i][j]!=0) chk_0 = false;
	// 		if(arr[i][j]!=-1) chk_minus1 = false;
	// 		if(arr[i][j]!=1) chk_plus1 = false;
	// 	}
	// }
	// if(chk_minus1) {
	// 	result[0]++;
	// 	return;
	// }
	// if(chk_0){
	// 	result[1]++;
	// 	return;
	// }
	// if(chk_plus1){
	// 	result[2]++;
	// 	return;
	// }

		
}
//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	int N; cin>>N;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin>>arr[i][j];
	Solve(0,0,N);
	for(auto x: result)
		cout<<x<<endl;
    return 0;
}