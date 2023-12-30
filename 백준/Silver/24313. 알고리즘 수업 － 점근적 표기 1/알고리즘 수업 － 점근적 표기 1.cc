#include <iostream>

using namespace std;
int solve(int a0, int a1, int c, int n0)
{
    // a1 * x + a0 <= c * n => (c - a1) * n >= a0 (On 만족하는 n의 최소값)
    int exponent = c - a1;
    int term = exponent * n0 - a0; // 최소값에 의한 term
    return exponent < 0 || term < 0 ? 0 : 1;
}

int main()
{
    int a0, a1, c, n0;
    cin >> a1 >> a0;
    cin >> c;
    cin >> n0;
    cout << solve(a0, a1, c, n0);
    return 0;
}