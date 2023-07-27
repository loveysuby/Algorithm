#include <bits/stdc++.h>
using namespace std;
#define fastio                   \
	ios::sync_with_stdio(false); \
	cin.tie(NULL);               \
	cout.tie(NULL);
#define ll long long
int main()
{
	fastio;
	int T;
	cin >> T;
	while (T--)
	{
		ll st, end, i = 1;
		cin >> st >> end;
		ll dist = end - st;
		while (1)
		{
			//{(N-1)^2 + N} ~ N^2 (이전 제곱수와의 중간값< dist <제곱수)
			if (dist <= i * i)
			{
				cout << i * 2 - 1 << '\n';
				break;
			}
			// N^2  ~  {N^2 ~ N^2 + N} (제곱수< dist <다음 제곱수와의 중간값)
			else if (dist <= i * i + i)
			{
				cout << i * 2 << '\n';
				break;
			}
			i++;
		}
	}
}
