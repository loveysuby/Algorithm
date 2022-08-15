#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int d1, d2, d3, r;
    cin >> d1 >> d2 >> d3;

    if (d1 == d2 && d2 == d3) {
        r = 10000 + d1 * 1000;
    } else if (d1 == d2) {
        r = 1000 + d1 * 100;
    } else if (d2 == d3) {
        r = 1000 + d2 * 100;
    } else if (d3 == d1) {
        r = 1000 + d3 * 100;
    } else {
        int max = d1;
        if (d2 > max) max = d2;
        if (d3 > max) max = d3;
        r = max * 100;
    }
    cout << r;

    return 0;
}