#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
ll s_min, s_max;
int isSquare[1000001];

int main(){
	fastio;
	int ans = 0;
	cin>>s_min>>s_max;
	for(ll i = 2; i*i <= s_max; i++){
		//범위 내의 제곱수 제거 : idx를 min~max 사이 실수가 아니라 0부터 매핑했으므로,(굳이 min부터 시작해서 메모리 낭비할 필요가 없음)
		//제곱수 - 시작하는 수를 제곱수로 mod -> 해당 제곱수의 배수의 idx   
		ll st = i*i - s_min % (i*i);
		//시작하는 숫자가 제곱수 == min은 제곱수 or 제곱수의 배수-> idx 0 부터 제거시작
		if(st == i*i) st = 0;
		for(ll k = st;k <= s_max - s_min; k += i*i) isSquare[k] = 1;
	}
	for(int i = 0; i <= s_max - s_min; i++) ans += !isSquare[i];
	cout<<ans;
}