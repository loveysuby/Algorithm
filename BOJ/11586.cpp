#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int size;
    cin >> size;

    cin.ignore();
    vector<string> mirrorStack;

    for (int i = 0; i < size; i++)
    {
        string faceInput;
        getline(cin, faceInput);
        mirrorStack.push_back(faceInput);
    }

    int status;
    cin >> status;
    switch (status)
    {
    case 1:
        for (int i = 0; i < size; i++)
            cout << mirrorStack[i] << '\n';
        return 0;
    case 2:
        for (int i = 0; i < size; i++)
        {
            for (int j = size - 1; j >= 0; j--)
                cout << mirrorStack[i][j];
            cout << '\n';
        }
        return 0;
    case 3:
        for (int i = size - 1; i >= 0; i--)
            cout << mirrorStack[i] << '\n';
        return 0;
    }
}