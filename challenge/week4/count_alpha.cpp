#include <iostream>
using namespace std;

int main()
{
    int vowel = 0;
    int consonant = 0;
    cout <<"영문자를 입력하고 A를 치세요" << endl;
    char ch=1;
    while(ch !='A'){
        cin >> ch ;
        switch (ch) {
            case 'a':
            case 'o':
            case 'i':
            case 'e':
            case 'u':
                vowel ++ ;
                break;
            case 'b':
            case 'c':
            case 'd':
            case 'f':
            case 'g':
            case 'h':
            case 'j':
            case 'k':
            case 'l':
            case 'm':
            case 'n':
            case 'p':
            case 'q':
            case 'r':
            case 's':
            case 't':
            case 'v':
            case 'w':
            case 'x':
            case 'y':
            case 'z':
                consonant ++;
                break;
            default :
                cout << "잘못 입력하셨습니다." << endl;
                break;
        
        }
    }
    cout << "모음 : " << vowel << endl;
    cout << "자음 : " << consonant << endl;
    return 0;
}