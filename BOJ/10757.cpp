#include <bits/stdc++.h>
using namespace std;

string solve(string a, string b) {
    string r = "";
    int tmp = 0;
    while (!a.empty() || !b.empty() || tmp) {
        if (!a.empty()) tmp += a.back() - '0', a.pop_back();
        if (!b.empty()) tmp += b.back() - '0', b.pop_back();
        r.push_back((tmp % 10) + '0');
        tmp /= 10;
    }
    reverse(r.begin(), r.end());
    return r;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string a, b;
    cin >> a >> b;
    cout << solve(a, b);
    return 0;
}