#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<int> v;
    for (int i = 0; i < 9; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    cout << *max_element(v.begin(), v.end()) << "\n";
    cout << max_element(v.begin(), v.end()) - v.begin() + 1;
    return 0;
}