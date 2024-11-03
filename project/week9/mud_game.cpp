#include <iostream>
#include <string>
using namespace std;

const int mapX = 5;
const int mapY = 5;
// 사용자 정의 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
bool moving(string user_input, int &user_hp, int map[][mapX], int &user_x, int &user_y);
void checkState(int map[][mapX], int &user_hp, int user_x, int user_y);
// 메인  함수
int main()
{
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
	int map[mapY][mapX] = {{0, 1, 2, 0, 4},
						   {1, 0, 0, 2, 0},
						   {0, 0, 0, 0, 0},
						   {0, 2, 3, 0, 0},
						   {3, 0, 0, 0, 2}};
	// 유저의 위치를 저장할 변수
	int user_x = 0; // 가로 번호
	int user_y = 0; // 세로 번호
	int user_hp = 20; // 사용자의 체력
	// 게임 시작
	while (1)
	{ // 사용자에게 계속 입력받기 위해 무한 루프

		// 사용자의 입력을 저장할 변수
		string user_input = "";
		cout << "명령어를 입력하세요 (w(up),s(down),a(left),d(right),map,exit): ";
		cin >> user_input;
		// 종료 여부를 체크한다.
		if (user_input == "exit" || user_hp <= 0) {
            user_hp == 0 ? cout << "체력이 0이 되어 종료합니다. 실패했습니다." << endl : cout << "종료합니다." << endl;
            break;
        }
		// moving함수를 호출하고 그 반환 값이 true이면 다음행동을 진행하고 false면 다시 입력을 받는다.
		if (!moving(user_input, user_hp, map, user_x, user_y))
		{
			cout << "잘못된 입력입니다. 다시 돌아갑니다." << endl;
			continue;
		}
		displayMap(map, user_x, user_y);
		checkState(map, user_hp, user_x, user_y); 
		// 목적지에 도달했는지 체크
		bool finish = checkGoal(map, user_x, user_y);
		if (finish == true)
		{
			cout << "목적지에 도착했습니다! 축하합니다!" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}
	}
	return 0;
}

void checkState(int map[][mapX], int &user_hp, int user_x, int user_y)
{	
	string state = "";
	int posState = map[user_y][user_x];
	switch (posState)
	{
	case 1:
		state = "아이템";
		break;
	case 2:
		state = "적";
		cout << "적을 만나 HP가 2 감소합니다." << endl;
		user_hp = user_hp-2;
		break;
	case 3:
		state = "포션";
		cout << "포션 효과로 HP가 2 치유됩니다." << endl;
		user_hp = user_hp +2;
		break;
	default :
		break;
	}
	cout << "HP : " << user_hp << "\t";
	if (state != "") cout << state << " 이/가 있습니다." <<endl;
	else cout << endl;
}

// 지도와 사용자 위치 출력하는 함수
void displayMap(int map[][mapX], int user_x, int user_y)
{
	for (int i = 0; i < mapY; i++)
	{
		for (int j = 0; j < mapX; j++)
		{
			if (i == user_y && j == user_x)
			{
				cout << " USER |"; // 양 옆 1칸 공백
			}
			else
			{
				int posState = map[i][j];
				switch (posState)
				{
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

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool checkXY(int user_x, int mapX, int user_y, int mapY)
{
	bool checkFlag = false;
	if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY)
	{
		checkFlag = true;
	}
	return checkFlag;
}

// 유저의 위치가 목적지인지 체크하는 함수
bool checkGoal(int map[][mapX], int user_x, int user_y)
{
	// 목적지 도착하면
	if (map[user_y][user_x] == 4)
	{
		return true;
	}
	return false;
}

// 유저의 위치를 옮기는 함수
bool moving(string user_input, int &user_hp, int map[][mapX], int &user_x, int &user_y)
{
	int index = 0;
	int buf_x, buf_y; // 임시로 움질일 위치를 저장
	int directions[5][2] = {
		// wasd에 따른 상대적 위치 정보
		{0, 0},	 // 움직이지 않음.
		{-1, 0}, // 상 (위로 이동)
		{1, 0},	 // 하 (아래로 이동)
		{0, -1}, // 좌 (왼쪽으로 이동)
		{0, 1}	 // 우 (오른쪽으로 이동)
	};
	if (user_input == "w")
		index = 1;
	else if (user_input == "s")
		index = 2;
	else if (user_input == "a")
		index = 3;
	else if (user_input == "d")
		index = 4;
	else if (user_input == "map")
		index = 0;
	else
	{
		return false;
	}

	buf_x = user_x + directions[index][1];
	buf_y = user_y + directions[index][0];
	if (!checkXY(buf_x, mapX, buf_y, mapY)){
		cout << "지도의 범위를 벗어났습니다" << endl;
		return false; }
		// buf_x, buf_y에 값이 true라면 hp를 깍고 실제 위치로 적용한다.
	else
	{
		user_hp--;
		user_x = buf_x;
		user_y = buf_y;
		if (index == 0)
			user_hp++; // map이나 exit과 같이 제자리 움직임의 경우 hp를 다시 회복시켜줌.
		return true;
	}
	cout << "debug 0" << endl; // 조건문의 예외가 발생함.
}
