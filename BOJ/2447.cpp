#include <iostream>
using namespace std;

void star(int x, int y, int cell)
{
    if ((x / cell) % 3 == 1 && (y / cell) % 3 == 1)
        cout << ' ';
    else if (cell / 3 == 0)
        cout << '*';
    else
        star(x, y, cell / 3);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            star(i, j, N);
        cout << '\n';
    }

    return 0;
}