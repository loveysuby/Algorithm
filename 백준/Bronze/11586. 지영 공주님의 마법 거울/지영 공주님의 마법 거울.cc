#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int s;
    cin >> s;

    cin.ignore();
    vector<string> m;

    for (int i = 0; i < s; i++)
    {
        string f;
        getline(cin, f);
        m.push_back(f);
    }

    int state;
    cin >> state;
    switch (state)
    {
    case 1:
        for (int i = 0; i < s; i++)
            cout << m[i] << endl;
        return 0;
    case 2:
        for (int i = 0; i < s; i++)
        {
            for (int j = s - 1; j >= 0; j--)
                cout << m[i][j];
            cout << endl;
        }
        return 0;
    case 3:
        for (int i = s - 1; i >= 0; i--)
            cout << m[i] << endl;
        return 0;
    }
}