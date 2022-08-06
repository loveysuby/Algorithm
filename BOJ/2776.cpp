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
using namespace std;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, N, Q;
    cin >> T;
    while (T--) {
        vi v;
        cin >> N;
        for0(i, N) {
            int num;
            cin >> num;
            v.pb(num);
        }
        sort(all(v));
        cin >> Q;
        for0(i, Q) {
            int target;
            cin >> target;
            cout << (int)binary_search(all(v), target) << '\n';
        }
    }
    return 0;
}