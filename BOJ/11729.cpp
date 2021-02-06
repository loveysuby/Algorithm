#include <iostream>
using namespace std;

/*
탑의 구성 : 1     2     3   
            x   6-x-y   y   [1+2+3 = 6]

calcHanoi 1번 돌릴 때 결과 : n개 블록을 x에서 y로 옮김 
Routine
1. 1번 탑에서 2번 탑으로 n-1개 블록 옮겨준다. (n-1번 반복)
2. 1번 과정에서 n이 1이 될 때는 x->y로 하나 블록만 옮기면 됨. 출력해준다.
3. 앞의 과정 끝나면 1번 탑의 맨 밑 블록만 3번에 가있고, 2번에도 규칙에 맞게 쌓여있다.
4. 이번엔 2번 탑(6-x-y)에서 3번 탑(y)로 쌓여있는 전체 블록(n-1 개) 다 옮겨준다.
*/
void calcHanoi(int n, int x, int y)
{
    if (n <= 1)
    {
        cout << x << ' ' << y << '\n';
        return;
    }
    calcHanoi(n - 1, x, 6 - x - y);
    cout << x << ' ' << y << '\n';
    calcHanoi(n - 1, 6 - x - y, y);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    cout << (1 << n) - 1 << '\n';
    calcHanoi(n, 1, 3);

    return 0;
}
