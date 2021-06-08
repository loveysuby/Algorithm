//Header
#include <bits/stdc++.h>
//Define
using namespace std;

//Global elements
bool chk[246913];

//Function


//Driver
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
	
	int n, cnt; 
	while(true){
		cin>>n;	
		if(n==0) break;
		
		cnt = 0;
		for(int i =2; i<=n*2 ; i++)
			chk[i] = true;
		for(int i =2;i<=sqrt(n*2);i++){
			if(chk[i]){
				for(int j = i * 2 ; j<= n*2; j += i){
					if(chk[j])
						chk[j] = false;
				}
			}
		}
		for(int i = n+1;i<= n*2;i++)
			if(chk[i]) cnt++;
		
		cout<<cnt<<'\n';
	}
    return 0;
}
