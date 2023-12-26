#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    cout << s.substr(s.size() - 5, 5);
    return 0;
}