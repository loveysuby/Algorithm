#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M, A[100001];
int isHere(int num)
{
    int st = 0, end = N - 1;
    while (st <= end)
    {
        int mid = (st + end) / 2;
        if (A[mid] < num)
            st = mid + 1;
        else if (A[mid] > num)
            end = mid - 1;
        else
            return 1;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    sort(A, A + N);
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int x;
        cin >> x;
        cout << isHere(x) << '\n';
    }
    return 0;
}
