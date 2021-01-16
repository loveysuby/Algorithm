#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>

using namespace std;
string NumStrIndex[100001];
int main(void)
{
    map<string, int> StrNumIndex;
    int x, y;
    scanf("%d %d", &x, &y);
    for (int i = 1; i <= x; i++)
    {
        char temp[1000];
        scanf("%s", temp);
        NumStrIndex[i] = temp;
        StrNumIndex[temp] = i;
    }
    while (y--)
    {
        char temp[1000];
        scanf("%s", temp);
        string s = temp;
        if (s[0] >= '0' && s[0] <= '9')
            cout << NumStrIndex[stoi(s)] << '\n';
        else
            cout << StrNumIndex[s] << '\n';
    }
    return 0;
}