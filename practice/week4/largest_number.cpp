#include <iostream>
using namespace std;

int main()
{
    int a, b, c, largest;
    
    cout << "3개의 정수를 입력하시오: ";
    cin >> a >> b >> c;

    if (a >= b && a >= c)       // 기존 관계연산자 '>' 는 정수 두개가 같으면 false를 반환한다. 
        largest = a;            // and연산은 앞에 식이 false가 뜨면 뒤에 식을 검사하지 않는다. 
    else if (b >= a && b >=c)   // 7 7 2와 같은 값이 들어오면  largest에 제일 작은 값이 들어가게 된다.
        largest = b ;           // 부등호 기호를 추가해 같은 값이 들어왔을 때 false가 되지 않도록 하여, 
    else                        // 뒤에 오는 값과의 비교가 가능하게 한다.
        largest = c ;

    cout << "가장 큰 정수는 " << largest << endl;
    return 0;
}