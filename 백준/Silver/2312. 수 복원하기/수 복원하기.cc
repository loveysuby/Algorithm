#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);
using namespace std;

int main()
{
    fastio int T, N;
    vector<int> pme;

    pme.push_back(2);

    for (int i = 3; i <= 100000; i += 2)
    {
        bool isPrime = true;
        for (int j = 3; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            pme.push_back(i);
    }

    cin >> T;

    while (T--)
    {
        cin >> N;
        for (int i = 0; i <= pme.size(); i++)
        {
            if (N == 1)
                break;
            int mtCnt = 0;

            while ((N % pme[i]) == 0)
            {
                N /= pme[i];
                mtCnt++;
            }

            if (mtCnt)
                cout << pme[i] << ' ' << mtCnt << '\n';
        }
    }

    return 0;
}