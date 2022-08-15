#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
int main() {
    ll n, num = 1;
    ll ans = 0, sum = 0;
    cin >> n;
	while(1){
		sum += num;
		ans++;
		if(sum>n){
			ans--;
			break;
		}
		num++;
	}
	cout<<ans;
}