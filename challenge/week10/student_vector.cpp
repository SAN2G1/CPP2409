#include <vector>
#include <iostream>
using namespace std;
int main(void)
{
    vector<int> student;
    int input;
    while (true)
    {
        cout << "성적을 입력하시오(종료는 -1) : ";
        cin >> input;
        if (input == -1){
            break ;
        }
        student.push_back(input);
    }
    int sum = 0;
    for (auto number : student)
    {
        sum += number;
    }
    if(student.size() == 0) {
        cout << "아무것도 입력하지 않았습니다." << endl;
        return 0;
    }
    cout << "성적 평균 : " << sum / student.size();
    cout << endl;
    return 0;
}