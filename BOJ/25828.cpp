#include <bits/stdc++.h>
using namespace std;

int main()
{
    int g, p, t;
    cin >> g >> p >> t;
    int each = g * p;
    int group = g + p * t;
    cout << (each < group ? 1 : each > group ? 2
                                             : 0)
         << endl;
    return 0;
}
