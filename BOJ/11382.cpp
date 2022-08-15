#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    long long int A, B, C;
    cin >> A >> B >> C;
    B += A;
    C += B;
    cout << C;
    return 0;
}