#include <iostream>
using namespace std;

int main()
{
    int have_m = 0, candy_p = 0;
    cout << "현재 가지고 있는 돈: ";
    cin >> have_m ;
    cout << "캔디의 가격: ";
    cin >> candy_p;
    cout << "최대로 살 수 있는 캔디 = " << have_m / candy_p << endl;
    cout << "캔디 구입 후 남은 돈 = " << have_m % candy_p << endl;

    return 0;
}