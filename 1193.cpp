#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int X;
    cin >> X;
    int i = 1;
    while (X > i) {
        X -= i;
        i++;
    }
    if (i % 2 == 1)
        cout << i + 1 - X << '/' << X << "\n";
    else
        cout << X << '/' << i + 1 - X << "\n";
    return 0;
}