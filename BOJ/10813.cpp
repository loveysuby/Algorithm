#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int *arr = new int[n + 1];
    for (int i = 1; i <= n; i++)
        arr[i] = i;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        swap(arr[a], arr[b]);
    }
    for (int i = 1; i <= n; i++)
        cout << arr[i] << ' ';
    return 0;
}