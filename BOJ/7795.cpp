#include <bits/stdc++.h>
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

void vecInput(int size, vector<int>& v) {
    for0(i, size) {
        int num;
        cin >> num;
        v.push_back(num);
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        vector<int> va, vb;
        int N, M, R = 0;

        cin >> N >> M;

        vecInput(N, va), vecInput(M, vb);
        sort(all(va)), sort(all(vb));

        for0(i, (int)vb.size())
            R += upper_bound(all(va), vb[i]) - va.begin();
        cout << (int)(va.size() * vb.size()) - R << '\n';
    }
    return 0;
}