#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    int lis[101];  // i개의 줄이 있을 때 겹치는 줄의 개수 (lis의 길이)

    vector<pair<int, int>> v;
    
    for (int i = 0; i < N; i++) {
        int tx, ty;
        cin >> tx >> ty;
        v.push_back(make_pair(tx, ty));
    }

    //first 기준으로 sort하면 second 원소중에서 꾸려진 lis가 곧 서로 안겹치는 라인의 집합
    sort(v.begin(), v.end()); 
    
    lis[0] = 1;
    
    for (int i = 1; i < N; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++) {
            if (v[j].second < v[i].second)
                lis[i] = max(lis[i], lis[j] + 1);
        }
    }
    
    cout << N - *max_element(lis, lis + N);
    
    return 0;
}