#include <iostream>
using namespace std;

int main()
{
    int a, b, c, largest;
    
    cout << "3개의 정수를 입력하시오: ";
    cin >> a >> b >> c;

    largest = a;
    if (largest < b) {
        if (b < c ) largest = c;
        else largest = b;
    }
    else if (largest < c)
        largest = c ;
        cout << "가장 큰 정수는 " << largest << endl;
    return 0;
}