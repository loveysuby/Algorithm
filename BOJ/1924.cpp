#include <iostream>
#include <string>
using namespace std;

int main()
{
    int daysAtMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string daysOnWeek[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int month, day;
    cin >> month >> day;
    //월별로 저장해둔 요일 수를 for로 접근, input day값에 더해 총 일수 구함
    for (int i = 1; i < month; i++)
        day += daysAtMonth[i];
    //day % 7 의 value == 일요일(0) 부터 시작되는 string 배열의 index
    cout << daysOnWeek[day % 7];

    return 0;
}
