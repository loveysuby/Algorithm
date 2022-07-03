#include <bits/stdc++.h>
using namespace std;
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);
#define MAX 1000001
int main() {
    fastio;
    int arr[MAX];
    string s;
    cin >> s;
    int res = 0;
    // 0, 1 바뀌는 포인트 개수 / 2 = 정답
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[i - 1])
            res++;
    }
    //답 1일때 보정
    cout << (res + 1) / 2;
}