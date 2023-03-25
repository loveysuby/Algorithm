#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp % 42);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    cout << v.size();
    return 0;
}