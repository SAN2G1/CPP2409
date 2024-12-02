#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Data
{
public:
    int hour;
    double temperature;
};
int main()
{
    ifstream is{"temp.txt"};
    if (!is)
    {
        cerr << "파일 오픈에 실패하였습니다." << endl;
        exit(1);
    }
    vector<Data> temps;
    int hour;
    double temperature;

    while (is >> hour >> temperature)
    {
        temps.push_back(Data{hour, temperature});
    }

    for (Data d : temps)
    {
        cout << d.hour << "시 : 온도 " << d.temperature << endl;
    }
    return 0;
}