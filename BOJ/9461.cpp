#include <iostream>
#include <vector>
using namespace std;

long long dp[1001] = {0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9};

long long padovan(int n)
{
    if (dp[n])
        return dp[n];
    else
        return (dp[n] = padovan(n - 1) + padovan(n - 5));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count, num;
    cin >> count;
    while (count--)
    {
        cin >> num;
        cout << padovan(num) << '\n';
    }
    return 0;
}