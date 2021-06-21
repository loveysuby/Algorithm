#include <bits/stdc++.h>
//Define
using namespace std;

//Global elements

int N,r,c, result=-1;
//Function
void Solve(int size,int x,int y){
	if(size ==2){ // z format search
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				int ptx = x + i;
				int pty = y + j;
				result++;
				if(r==ptx && c==pty){
					cout<<result;
					return;
				}
			}
		}
		return;
	}
	if(r<x+size/2&&c<y+size/2)
		Solve(size/2,x,y);
	else if(r<x+size/2&&c>=y+size/2){
		result += pow(size/2,2);
		Solve(size/2,x,y+size/2);
	}
	else if(r>=x+size/2&&c<y+size/2){
		result += 2 * pow(size/2,2);
		Solve(size/2,x+size/2,y);
	}
	else{
		result += 3 * pow(size/2,2);
		Solve(size/2,x+size/2,y+size/2);
	}
	return;
}

//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>N>>r>>c;
	Solve(pow(2,N),0,0);
	
    return 0;
}
