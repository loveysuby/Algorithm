#include <bits/stdc++.h>
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define forr0(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i)
#define pb push_back
#define pob pop_back
#define fi first
#define se second
#define mp make_pair
#define sz(a) int((a).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
typedef double ld;
using namespace std;
#define MAX_GAMES 1000000000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll game, wins;
    cin >> game >> wins;

    ll st = 0, en = MAX_GAMES;
    ll rate = 100 * wins / game;
    if (rate > 98)
        st = -1;
    else {
        while (st <= en) {
            ll mid = (st + en) / 2;
            ll tmpr = 100 * (mid + wins) / (mid + game);
            if (rate < tmpr)
                en = mid - 1;
            else
                st = mid + 1;
        }
    }

    cout << st << '\n';
}