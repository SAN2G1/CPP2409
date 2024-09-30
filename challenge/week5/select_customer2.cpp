#include <iostream>
#include <string>
using namespace std;

int main() {
    const int maxPeople = 5;
    string names[maxPeople];
    int ages[maxPeople];
    cout << maxPeople << "명의 회원 정보를 입력해주세요." << endl;

    for (int i = 0; i < maxPeople; i++) {
        cout << "사람 " << i + 1 << "의 이름: ";
        cin >> names[i];
        cout << "사람 " << i + 1 << "의 나이: ";
        cin >> ages[i];
    }

    int max = -999, min = 999;
    int max_count = 0, min_count = 0;
    string max_names[maxPeople];
    string min_names[maxPeople];

    for (int i = 0; i < maxPeople; i++) {
        if (ages[i] > max) {
            max = ages[i];
            max_count = 0;
            max_names[max_count] = names[i];
            max_count++;
        } else if (ages[i] == max) {
            max_names[max_count] = names[i];
            max_count++;
        }
    }

    for (int i = 0; i < maxPeople; i++) {
        if (ages[i] < min) {
            min = ages[i];
            min_count = 0;
            min_names[min_count] = names[i];
            min_count++;
        } else if (ages[i] == min) {
            min_names[min_count] = names[i];
            min_count++;
        }
    }

    int choice;

    while (1) {
        cout << "1. 가장 나이가 많은 사람 출력" << endl;
        cout << "2. 가장 나이가 적은 사람 출력" << endl;
        cout << "3. 종료" << endl;
        cout << ">> ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "가장 나이가 많은 사람: " << endl;
                for (int i = 0; i < max_count; i++) {
                    cout << max_names[i] << " " << max << "세" << endl;
                }
                break;
            }
            case 2: {
                cout << "가장 나이가 적은 사람: " << endl;
                for (int i = 0; i < min_count; i++) {
                    cout << min_names[i] << " " << min << "세" << endl;
                }
                break;
            }
            case 3:
                cout << "프로그램을 종료합니다." << endl;
                return 0;
            default:
                cout << "잘못된 선택입니다." << endl;
                break;
        }
    }

    return 0;
}

