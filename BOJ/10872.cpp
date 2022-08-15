#include <iostream>
#define ll long long
using namespace std;

ll factorial(int n)
{
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll num = 0;
    cin >> num;

    cout << factorial(num);
    return 0;
}