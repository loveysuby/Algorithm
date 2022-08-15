#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    vector<int> v, vsum;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)  // allow duplicate element to maximize result
            vsum.push_back(v[i] + v[j]);
    sort(vsum.begin(), vsum.end());
    for (int i = N - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (binary_search(vsum.begin(), vsum.end(), v[i] - v[j])) {
                cout << v[i];
                return 0;
            }
        }
    }
}