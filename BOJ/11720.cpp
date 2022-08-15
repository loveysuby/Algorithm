#include <iostream>
using namespace std;

int main()
{
    int count, sum = 0;
    //숫자만 들어온다는 전제 : ASCII 를 이용해서 빼준다.
    char number;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cin >> number;
        //만약 숫자만이 아니라면 ?: int vector stack->pop > sum
        sum += number - 48;
    }
    cout << sum;
    return 0;
}