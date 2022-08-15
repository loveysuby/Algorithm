#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int sum, prefix;
    cin >> sum >> prefix;
    for (int i = 0; i < prefix; i++) {
        int price, cnt;
        cin >> price >> cnt;
        sum -= price * cnt;
    }
    if (sum == 0)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}