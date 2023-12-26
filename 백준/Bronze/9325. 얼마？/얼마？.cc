#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int s, n;
        cin >> s >> n;
        while (n--)
        {
            int q, p;
            cin >> q >> p;
            s += q * p;
        }
        cout << s << endl;
    }
}