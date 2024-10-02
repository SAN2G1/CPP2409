#include <iostream>
using namespace std;

int main()
{
    const int numCell = 3; 
    char board[numCell][numCell]{};
    int x, y;

    // 보드를 초기화
    for(x = 0; x < numCell ; x++)
    {
        for(y = 0; y < numCell; y++)
        {
            board[x][y] = ' ';
        }
    }

    int k = 0;
    char currentUser = 'X'; // 유저의 돌을 가지고 있는 변수

    while(true) {

        // 1. 누구의 차례인지 출력
        switch(k % 2)
        {
            case 0:
                cout << "첫번째 유저 (X)의 차례입니다 ->";
                currentUser = 'X';
                break; 
            case 1: 
                cout << "두번째 유저 (O)의 차례입니다 ->";
                currentUser = 'O';
                break;
        }

        // 2. 좌표 입력 받기
        cout << "(x, y) 좌표를 입력하세요: ";
        cin >> x >> y;

        // 3. 입력 받은 좌표의 유효성 체크 
        if (x >= numCell || y >= numCell)
        {
            cout << x << ", " << y << ": ";
            cout << "x와 y 둘 중 하나가 칸을 벗어납니다." << endl;
            continue;
        }
        if (board[x][y] != ' ')
        {
            cout << x << ", " << y << ": 이미 돌이 차 있습니다." << endl;
            continue;
        }

        // 4. 입력받은 좌표에 현재 유저의 돌 놓기
        board[x][y] = currentUser;

        // 5. 보드 출력
        for(int i = 0; i < numCell; i++)
        {
            cout << "---|---|---" << endl;
            for(int j = 0; j < numCell; j++)
            {
                cout << board[i][j]; 
                if (j == numCell - 1) {
                    break;
                }
                cout << "  |";
            }
            cout << endl;
        }
        cout << "---|---|---" << endl;

        // 6. 빙고 시 승자 출력 후 종료
        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ') || 
                (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')) 
            {
                cout << "축하합니다. 승리자는 " << ((k % 2 == 0) ? "1번 유저(X)" : "2번 유저(O)") << " 입니다." << endl;
                return 0;
            }
        }

        if ((board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ') || 
            (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')) 
        {
            cout << "축하합니다. 승리자는 " << ((k % 2 == 0) ? "1번 유저(X)" : "2번 유저(O)") << " 입니다." << endl;
            return 0;
        }

        // 7. 모든 칸이 찼으면 종료
        if (k == 8) {
            cout << "칸이 모두 찼습니다. 게임을 종료합니다." << endl;
            return 0;
        }
        k++;
    }

    return 0;
}
