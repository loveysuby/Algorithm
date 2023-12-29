#include <iostream>
#include <vector>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, C;
    cin >> A >> B;
    cin >> C;
    A += C / 60;
    B += C % 60;
    if (B >= 60)
    {
        A += B / 60;
        B %= 60;
    }
    if (A >= 24)
        A %= 24;
    cout << A << ' ' << B;
}