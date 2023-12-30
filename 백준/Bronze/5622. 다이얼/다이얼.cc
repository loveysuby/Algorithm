#include <iostream>
#include <vector>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);

using namespace std;

int main()
{
    fastio;
    int res = 0;
    string s;
    cin >> s;
    for (char c : s)
    {
        if (c <= 'C')
            res += 3;
        else if (c <= 'F')
            res += 4;
        else if (c <= 'I')
            res += 5;
        else if (c <= 'L')
            res += 6;
        else if (c <= 'O')
            res += 7;
        else if (c <= 'S')
            res += 8;
        else if (c <= 'V')
            res += 9;
        else
            res += 10;
    }
    cout << res;
    return 0;
}