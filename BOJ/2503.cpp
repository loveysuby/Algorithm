#include <bits/stdc++.h>
using namespace std;
bool num[1001];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T, res = 0;
    cin >> T;
    fill(num, num + 1001, true);
    for (int i = 100; i <= 999; i++) {
        string chke = to_string(i);
        if (chk[0] - '0' == 0 || chk[1] - '0' == 0 || chk[2] - '0' == 0) {
            num[i] = false;
            continue;
        }
        if (chk[0] == chk[1] || chk[1] == chk[2] || chk[2] == chk[0]) {
            num[i] = false;
            continue;
        }
    }
    for (int i = 0; i < T; i++) {
        int input, st, ba;
        cin >> input >> st >> ba;

        string sinput = to_string(input);

        for (int i = 100; i <= 999; i++) {
            if (num[i]) {
                string cmp = to_string(i);
                int stCnt = 0, baCnt = 0;
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        if (x != y && sinput[x] == cmp[y]) {
                            baCnt++;
                            continue;
                        }
                        if (x == y && sinput[x] == cmp[y]) {
                            stCnt++;
                            continue;
                        }
                    }
                }
                if (st != stCnt || ba != baCnt) {
                    num[i] = false;
                    continue;
                }
            }
        }

        for (int i = 100; i <= 999; i++)
            if (num[i] == true) res++;

        cout << res;
        return 0;
    }