#include <bits/stdc++.h>
using namespace std;

string S, v[101];
int cache[101], A;

bool f(int pos) {
    int& ret = cache[pos];

    if (ret != -1) return ret;  // base
    if (pos == S.size()) return true;

    ret = 0;

    for (int i = 0; i < A; i++) {
        if (S.size() < v[i].size() + pos)  //해당 단어가 타깃보다 긴 경우
            continue;
        if (v[i] == S.substr(pos, v[i].size()))  // loop case
            ret += f(pos + v[i].size());
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(cache, -1, sizeof(cache));
    cin >> S >> A;
    for (int i = 0; i < A; i++)
        cin >> v[i];
    cout << f(0);

    return 0;
}