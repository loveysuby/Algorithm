#include <iostream>
#define ll long long
#define billion 1000000000
using namespace std;

ll result = 0;
int N, cache[101][10];

/* 
1의 자리 숫자부터 뭐가 될지 정해져야 계단 수를 정의할 수 있는 듯 
(반대로도 상관없겠지만 10의 제곱으로 mod 할 수 있으니까 이렇게 시작해봤다. 0으로 시작할 수 없어서기도 하다)

row가 1이면 (1~9) 무조건 계단수므로 총 9개
(2,6) = (1,5) + (1,7) = 2
(3,7) = (2.6) + (2,8) = 4
(4,8) = (3,7) + (3,9) =? 

0이랑 9가 1의 자리수인 경우 -> 다음 자리수에 2개 수가 올 수 없다. (0이면 1만, 9면 8만 가능)

(3,0) = (2,1)
j = 0 , cache[i][j] = cache[i-1][j+1]
(3,9) = (2,8)
j = 9 , cache[i][j] = cache[i-1][j-1]

j = else , cache[i][j] = cache[i-1][j+1] + cache[i-1][j-1];

sum = (N,0) ~ (N,9);
*/

int main(void)
{
	for(int i=0; i<=9;i++)
		cache[1][i] =1;
	
	cin>>N;
	
	for(int i =2;i<N;i++){
		for(int j=0;j<=9;j++){
			if(j==0)
				cache[i][j] = cache[i-1][j+1] % billion;
			else if(j==9)
				cache[i][j] = cache[i-1][j-1] % billion;
			else
				cache[i][j] = cache[i-1][j+1] + cache[i-1][j-1] % billion;
		}
	}
	for(int i=0;i<10;i++)
		sum += cache[N][i];
	cout<<sum % billion;
	return 0;	
}