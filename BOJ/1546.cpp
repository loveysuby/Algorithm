#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N;
    float S;
    cin >> N;
    vector<float> v;
    for (float i = 0; i < N; i++) {
        float tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    float max_score = *max_element(v.begin(), v.end());
    for (int i = 0; i < N; i++) {
        v[i] = v[i] / max_score * 100;
        S += v[i];
    }
    cout << S / N;
    return 0;
}