#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int A, B, V;
    cin >> A >> B >> V;
    cout << (V - B - 1) / (A - B) + 1;
    return 0;
}