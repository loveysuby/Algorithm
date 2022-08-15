#include <iostream>

using namespace std;

bool pixel[105][105];

void calcPixel(int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            bool chk;
            cin >> chk;
            for (int x = i * k; x < i * k + k; x++)
                for (int y = j * k; y < j * k + k; y++)
                    pixel[x][y] = chk;
        }
    }
}
void displayPixel(int n, int k)
{
    for (int i = 0; i < n * k; i++)
    {
        for (int j = 0; j < n * k; j++)
            cout << pixel[i][j] << ' ';
        cout << '\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    calcPixel(n, k);
    displayPixel(n, k);

    return 0;
}