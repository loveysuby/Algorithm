#include <bits/stdc++.h>
using namespace std;

bool chk[201][201][201];
bool visited[201];
int A, B, C; // A, B, C 물통의 용량,  a,b,c : 현재 물통의 물의 양
vector<int> res;
void solve(int a, int b, int c) // a->b->c 를 bfs로 돌면서 물통 용량을 넘지 않는 모든 경우의 수를 탐색
{
    if (chk[a][b][c])
        return;
    chk[a][b][c] = true;
    if (a == 0 && !visited[c])
    {
        res.push_back(c);
        visited[c] = true;
    }

    int nc = C - c; // c에 넣을 수 있는 양 (옮겨줄 수 있는 양)
    int na = A - a;
    int nb = B - b;

    solve(max(0, a - nc), b, c + min(a, nc)); // a->c
    solve(max(0, a - nb), b + min(a, nb), c); // a->b
    solve(a, max(0, b - nc), c + min(b, nc)); // b->c
    solve(a + min(b, na), max(0, b - na), c); // b->a
    solve(a + min(c, na), b, max(0, c - na)); // c->a
    solve(a, b + min(c, nb), max(0, c - nb)); // c->b
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> A >> B >> C;
    solve(0, 0, C);
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << ' ';
    return 0;
}