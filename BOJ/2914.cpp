#include <iostream>
using namespace std;

int main()
{
    int song, avg;
    cin >> song >> avg;
    cout << song * (avg - 1) + 1;
    return 0;
}