#include <bits/stdc++.h>
using namespace std;
//Driver
int main()
{
	string input; cin>>input;
	int sum=0, temp=1;
	stack<int> s;
	for(int i=0;i<input.size();i++){
		switch(input[i]){
			case '(':
				temp *=2; s.push(input[i]); break;
			case '[':
				temp *=3; s.push(input[i]); break;			
			case ')':
				if(s.empty()||s.top()!='(') return !printf("0");
				if(input[i-1]=='(') sum += temp;
				temp/=2; s.pop(); break;
			case ']':
				if(s.empty()||s.top()!='[') return !printf("0");
				if(input[i-1]=='[') sum += temp;
				temp/=3; s.pop(); break;
		}
	}
	if(!s.empty()) sum = 0;
	cout<<sum;
    return 0;
}