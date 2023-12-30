#include <iostream>

using namespace std;

int main()
{
    int a0, a1, c, n0;
    cin >> a1 >> a0 >> c >> n0;
    cout << ((c - a1) < 0 || (c - a1) * n0 - a0 < 0 ? 0 : 1);
    return 0;
}