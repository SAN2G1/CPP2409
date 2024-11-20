#include <iostream>
#include <string>
#include <vector>
#include "user.h"
using namespace std;

const int MAP_X = 5;
const int MAP_Y = 5;

// 사용자 정의 함수
bool CheckXY(int x, int y);
void DisplayMap(const vector<vector<int>>& map, const vector<User*>& players);
bool CheckGoal(const vector<vector<int>>& map, User& player);
bool Moving(string user_input, const vector<vector<int>>& map, User& player);
void CheckState(const vector<vector<int>>& map, User& player);
bool CheckUser(User& user);

// 마법사 클래스 정의
class Magician : public User {
public:
    Magician(char i, int x, int y) : User(i, x, y) {}

    void DoAttak() {
        cout << "마법 사용" << endl;
    }
};

// 전사 클래스 정의
class Warrior : public User {
public:
    Warrior(char i, int x, int y) : User(i, x, y) {}

    void DoAttak() {
        cout << "베기 사용" << endl;
    }
};

// 메인 함수
int main() {
    // 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
    vector<vector<int>> map{
        {0, 1, 2, 0, 4},
        {1, 0, 0, 2, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 3, 0, 0},
        {3, 0, 0, 0, 2}};

    // 플레이어 관리
    vector<User*> players;
    players.push_back(new Magician{'M', 0, 0}); // Magician 객체
    players.push_back(new Warrior{'W', 3, 3});  // Warrior 객체

    int count = 0; // 게임 진행(이동 및 공격)에 따른 횟수
    int turn = 0;  // 현재 플레이어의 턴

    // 게임 시작
    while (true) {
        turn = count % 2; // 0일 때 Magician의 턴, 1일 때 Warrior의 턴

        string user_input = "";
        cout << "현재 player {" << players[turn]->GetIcon() << "} 입니다. "
             << "명령어를 입력하세요 (w(up),s(down),a(left),d(right),attack,map,info,exit): ";
        cin >> user_input;

        if (user_input == "info") {
            cout << *players[turn];
            continue;
        } else if (user_input == "exit") {
            cout << "종료합니다." << endl;
            break;
        } else if (user_input == "map") {
            DisplayMap(map, players);
            continue;
        } else if (user_input == "attack") {
            players[turn]->DoAttak();
            count++;
            continue;
        }



        if (!Moving(user_input, map, *players[turn])) {
            cout << "잘못된 입력입니다. 다시 돌아갑니다." << endl;
            continue;
        }

        DisplayMap(map, players);
        CheckState(map, *players[turn]);
        if (!CheckUser(*players[turn])) {
            cout << "체력이 0이 되어 종료합니다. " << players[turn] -> GetIcon() << "은 실패했습니다! " << endl;
            break;
        }

        if (CheckGoal(map, *players[turn])) {
            cout << players[turn]->GetIcon() <<"가 목적지에 도착했습니다! 축하합니다!" << endl;
            cout << "게임을 종료합니다." << endl;
            break;
        }
        count++;
    }

    // 동적 할당된 메모리 해제
    for (auto player : players) {
        delete player;
    }

    return 0;
}
// 사용자 상태를 체크하는 함수
bool CheckUser(User& user) {
    if (user.GetHp() <= 0)
        return false;
    else
        return true;
}

// 플레이어의 상태를 체크하는 함수
void CheckState(const vector<vector<int>>& map, User& player) {
    string state = "";
    int pos_state = map[player.y_point][player.x_point];
    switch (pos_state) {
    case 1:
        state = "아이템";
        player.IncItemCnt();
        break;
    case 2:
        state = "적";
        cout << "적을 만나 HP가 2 감소합니다." << endl;
        player.DecreaseHp(2);
        break;
    case 3:
        state = "포션";
        cout << "포션 효과로 HP가 2 치유됩니다." << endl;
        player.IncreaseHp(2);
        break;
    default:
        break;
    }
    cout << "HP : " << player.GetHp() << "\t";
    if (state != "")
        cout << state << " 이/가 있습니다." << endl;
    else
        cout << endl;
}

// 지도와 사용자 위치를 출력하는 함수
void DisplayMap(const vector<vector<int>>& map, const vector<User*>& players) {
    for (int i = 0; i < MAP_Y; i++) {
        for (int j = 0; j < MAP_X; j++) {
            vector<char> player_symbols;
            for (const auto& p : players) {
                if (p->x_point == j && p->y_point == i) {
                    player_symbols.push_back(p->GetIcon());
                }
            }

            if (!player_symbols.empty()) {
                if (player_symbols.size() > 1) {
                    cout << "  " << player_symbols[0] << " " << player_symbols[1] << " |"; // 겹친 경우
                } else {
                    cout << "   " << player_symbols[0] << "  |";
                }
            } else {
                int pos_state = map[i][j];
                switch (pos_state) {
                case 0:
                    cout << "      |"; // 6칸 공백
                    break;
                case 1:
                    cout << "아이템|";
                    break;
                case 2:
                    cout << "  적  |"; // 양 옆 2칸 공백
                    break;
                case 3:
                    cout << " 포션 |"; // 양 옆 1칸 공백
                    break;
                case 4:
                    cout << "목적지|";
                    break;
                }
            }
        }
        cout << endl;
        cout << " -------------------------------- " << endl;
    }
}

// 유저의 위치가 목적지인지 체크하는 함수
bool CheckGoal(const vector<vector<int>>& map, User& player) {
    if (map[player.y_point][player.x_point] == 4) {
        return true;
    }
    return false;
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool CheckXY(int x, int y) {
    return (x >= 0 && x < MAP_X && y >= 0 && y < MAP_Y);
}

// 유저의 위치를 옮기는 함수
bool Moving(string user_input, const vector<vector<int>>& map, User& player) {
    int index = 0;
    int buf_x, buf_y;
    int directions[5][2] = {
        {0, 0},  // 움직이지 않음
        {-1, 0}, // 상 (위로 이동)
        {1, 0},  // 하 (아래로 이동)
        {0, -1}, // 좌 (왼쪽으로 이동)
        {0, 1}   // 우 (오른쪽으로 이동)
    };

    if (user_input == "w")
        index = 1;
    else if (user_input == "s")
        index = 2;
    else if (user_input == "a")
        index = 3;
    else if (user_input == "d")
        index = 4;
    else {
        return false;
    }

    buf_x = player.x_point + directions[index][1];
    buf_y = player.y_point + directions[index][0];
    if (!CheckXY(buf_x, buf_y)) {
        cout << "지도의 범위를 벗어났습니다" << endl;
        return false;
    } else {
        player.DecreaseHp(1);
        player.x_point = buf_x;
        player.y_point = buf_y;
        if (index == 0)
            player.IncreaseHp(1); // map이나 exit과 같이 제자리 움직임의 경우 hp를 다시 회복시켜줌.
        return true;
    }
}
