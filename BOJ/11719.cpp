#include <iostream>
#include <string>
using namespace std;
#define MAX_LINE 100
int main()
{
    string str;
    for (int i = 0; i < MAX_LINE; i++)
    {
        getline(cin, str);
        cout << str << "\n";
    }
    //11718이랑 같음
    return 0;
}