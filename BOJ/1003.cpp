#include <iostream>
using namespace std;
int dp[41] = {
    0,
    1,
};
int fibo(int n)
{
    if (n == 0 || n == 1)
        return dp[n];
    else if (dp[n] == 0)
        dp[n] = fibo(n - 1) + fibo(n - 2);
    return dp[n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count, temp;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cin >> temp;
        if (temp == 0)
            cout << "1 0" << '\n';
        else
        {
            cout << fibo(temp - 1) << ' ' << fibo(temp) << '\n';
        }
    }
    return 0;
}