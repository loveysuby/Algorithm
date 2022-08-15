#include <bits/stdc++.h>
using namespace std;
int N;
bool isExist[21];
map <string,int> m;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	m["add"] = 0; m["remove"] = 1; m["check"] = 2;
	m["toggle"] = 3; m["all"] = 4; m["empty"] = 5;
	cin>>N;	
	while(N--){
		int elem = 0;
		char command[7];
		cin>>command;
		if(strcmp(command,"all") && strcmp(command,"empty"))
			cin>>elem;
		switch(m[command])
		{
			case 0:
				isExist[elem] = true;
				break;
			case 1:
				isExist[elem] = false;
				break;
			case 2:
				cout<<isExist[elem]<<"\n";
				break;
			case 3:
				isExist[elem] ^= 1;
				break;
			case 4:
				memset(isExist,true,sizeof(isExist));
				break;
			case 5:
				memset(isExist,false,sizeof(isExist));	
				break;
		}
	}
	return 0;
}