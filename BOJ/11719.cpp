#include <iostream>
#include <string>
using namespace std;
#define MAX_LINE 100
int main()
{
    //정적 배열로 입력받을 수는 없겠다 -> STL 어쩔 수 없이 사용
    string str;
    for (int i = 0; i < MAX_LINE; i++)
    {
        getline(cin, str);
        cout << str << "\n";
    }
    //11718이랑 같음
    return 0;
}