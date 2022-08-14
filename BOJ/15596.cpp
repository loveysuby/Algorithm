#include <bits/stdc++.h>
using namespace std;
int N;
long long sum(vector<int>& a) {
    long long int r = 0;
    for (int i = 0; i < N; i++;) r += a[i];
    return r;
}