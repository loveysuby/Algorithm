#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    printf("%d", N == (N & -N) ? 1 : 0);
}
