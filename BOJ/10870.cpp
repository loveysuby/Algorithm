#include <iostream>
using namespace std;

int cache[21] = {
    0,
    1,
    1,
};
int fibo(int n)
{
    if (n > 2)
        return cache[n] = fibo(n - 1) + fibo(n - 2);
    else
        return cache[n];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    cout << fibo(n);
    return 0;
}