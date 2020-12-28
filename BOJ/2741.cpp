#include <iostream>
//가급적 endl 대신 \n으로,, endl : output buffer를 시행마다 초기화시켜줌 >> \n 출력보다 느리다.
int main()
{
    int count;
    std::cin >> count;
    for (int i = 1; i <= count; i++)
        std::cout << i << "\n";
    return 0;
}