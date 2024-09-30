#include <iostream>
using namespace std;

int main()
{
    int floor;
    cout << "몇 층을 쌓겠습니까? (5~100): ";
    cin >> floor;
    
    int i = floor;
    while (i > 0) {
        int j = 0;
        
        while (j < floor - i) {
            cout << "S";
            j++;
        }
        
        j = 0;
        while (j < i * 2 - 1) {
            cout << "*";
            j++;
        }
        
        cout << endl;
        i--;
    }
    
    return 0;
}
