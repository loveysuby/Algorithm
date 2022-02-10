#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
	fastio;
	int N, F = 0; cin>>N;	
	if((N%4 == 0 && N%100 != 0) || N%400 == 0) F = 1;
	cout<< F ? 1 : 0;
}