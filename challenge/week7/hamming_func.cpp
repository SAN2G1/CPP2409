#include <iostream>
#include <string>
using namespace std;
string toLowerStr(string str);
string toUpperStr(string str);
int calcHammingDist(string s1, string s2);

int main(void)
{
    string s1, s2;

    cout << "DNA1: ";
    cin >> s1;
    cout << "DNA2: ";
    cin >> s2;
    while(s1.length() != s2.length()){
        cout << "오류: 길이가 다름" << endl;
        cout << "DNA1: ";
        cin >> s1;
        cout << "DNA2: ";
        cin >> s2;
        if (s1.length() == s2.length()) 
            break;
    }
    s1 =  toLowerStr(s1);
    s2 = toLowerStr(s2);
    int dist = calcHammingDist(s1,s2);
    cout << "해밍 거리는 " << dist << endl;
    return 0;
    
}

string toLowerStr(string str)
{   
    for (char &c : str)
        c = tolower(c);
    return str;
}
string toUpperStr(string str)
{   
    for (char &c : str)
        c = toupper(c);
    return str;
}
int calcHammingDist(string s1, string s2)
{   int count = 0;
    
    for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] != s2[i])
                count++ ;
        }
    return count ;
}