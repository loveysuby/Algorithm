#include <bits/stdc++.h>
using namespace std;

bool a[10001];
int d(int n) {
    return n + n / 1000 + n % 1000 / 100 +
           n % 100 / 10 + n % 10;
}

void setArray() {
    int curr;
    a[1] = false;
    for (int i = 0; i < 10000; i++) {
        if (i < 10000) {
            curr = d(i);
            if (curr < 10000)
                a[curr] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    setArray();
    for (int i = 1; i < 10000; i++)
        if (!a[i])
            cout << i << '\n';
    return 0;
}