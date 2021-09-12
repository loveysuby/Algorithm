#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

//Global elements
int cache[3000];
//Function

//Driver
int main()
{
	fastio;
	string s, tmp=""; cin>>s;
	int res = 0;
	bool minus = false;
	// minus 가 나오기만 하면 그 앞의 항을 전부 괄호 처리 하는 것이 최소해가 된다.
	for(int i=0;i<s.length();i++){
		if(s[i]=='+' || s[i]=='-'){
			if(minus)
				res -= stoi(tmp);
			else
				res += stoi(tmp);
			tmp = "";	
			if(s[i]=='-')
				minus = true;
		}
		else
			tmp += s[i];
	}
	if(minus)
		res -= stoi(tmp);
	else
		res += stoi(tmp);
	cout<<res;
	return 0;
}