#include <iostream>
#define ll long long
using namespace std;

ll cache[91] = {0,1,};

int main(void){
	int N;
	cin >> N;
	
    for(int i = 2; i <= N; i++)
		cache[i] = cache[i-1] + cache[i-2];

	cout << cache[N] <<'\n';
	
	return 0;
}