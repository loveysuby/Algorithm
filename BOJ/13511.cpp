#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
int N, M, depth[100005], pa[18][100005];
ll dist[100005];
vector<pii> vt[100005];

void moveNode(int n) {
    for (pii p : vt[n]) {
        int nn = p.first;
        if (nn != 1 && depth[nn] == 0) {
            depth[nn] = depth[n] + 1;
            dist[nn] = dist[n] + p.second;
            pa[0][nn] = n;
            moveNode(nn);
        }
    }
}

int LCA(int U, int V) {
    if (depth[U] > depth[V]) {
        for (int i = 17; i >= 0; --i) {
            if (U != V && depth[pa[i][U]] >= depth[V]) U = pa[i][U];
        }
    } else if (depth[U] < depth[V]) {
        for (int i = 17; i >= 0; --i) {
            if (U != V && depth[pa[i][V]] >= depth[U]) V = pa[i][V];
        }
    }
    for (int i = 17; i >= 0; --i) {
        if (U != V && pa[i][U] != pa[i][V]) {
            U = pa[i][U];
            V = pa[i][V];
        }
    }
    if (U == V) return U;
    return pa[0][U];
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> N;
    for (int i = 1, U, V, K; i < N; i++) {
        cin >> U >> V >> K;
        vt[U].push_back({V, K});
        vt[V].push_back({U, K});
    }

    depth[1] = 0;
    pa[0][1] = 1;
    moveNode(1);

    for (int i = 1; i <= 17; i++) {
        for (int j = 1; j <= N; j++) {
            pa[i][j] = pa[i - 1][pa[i - 1][j]];
        }
    }

    cin >> M;

    while (M--) {
        int U, V, K, d;
        cin >> U;

        if (U == 1) {
            cin >> V >> K;
            int p = LCA(V, K);
            cout << dist[V] + dist[K] - 2 * dist[p] << "\n";
        } else {
            cin >> V >> K >> d;
            int p = LCA(V, K), cnt = 0;
            if (d > depth[V] - depth[p] + 1) {
                d -= depth[V] - depth[p] + 1;
                d = (depth[K] - depth[p]) - d;

                while (d != 0) {
                    if (d % 2 == 1)
                        K = pa[cnt][K];
                    d /= 2;
                    cnt++;
                }
                cout << K << "\n";
            } else {
                d--;
                while (d != 0) {
                    if (d % 2 == 1)
                        V = pa[cnt][V];
                    d /= 2;
                    cnt++;
                }
                cout << V << "\n";
            }
        }
    }
    return 0;
}