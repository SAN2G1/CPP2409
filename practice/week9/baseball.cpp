#include <iostream>
#include <string>
using namespace std;
bool checkNum (int num){
    string strNum = to_string(num); // 자릿수를 비교하기 위해 정수형을 string으로 바꿈
        if (strNum[0] != strNum[1])
            if (strNum[0] != strNum[2])
                if (strNum[1] != strNum[2])
                    return true;    //모든 자릿수가 다르면 true를 반환
    return false;
}
void hint(int userNumber, int randomNum, int &strike , int &ball){
	string strUsr = to_string(userNumber);
    string strRand = to_string(randomNum);

    //스트라이크 체크
    for(int i = 0; i<3; i++){
        if (strUsr[i] == strRand[i] )
            strike++;
    }
    //볼체크
    if(strRand[0] == strUsr[1] || strRand[0] == strUsr[2]) ++ ball; // 맞출 첫 숫자와 두번째 세번째를 비교
    if(strRand[1] == strUsr[0] || strRand[1] == strUsr[2]) ++ ball; // 맞출 두번째 숫자와 첫번째, 세번째를 비교
    if(strRand[2] == strUsr[0] || strRand[2] == strUsr[1]) ++ ball; // 맞출 마지막 숫자와 첫번째, 두번째를 비교
	
}

int main() {
	int randomNum; // 맞춰야 하는 3자리수의 숫자 저장 변수
	int firstNum; // 정답의 첫번째 자리수
	int secondNum; // 정답의 두번째 자리수
	int thirdNum; // 정답의 세번째 자리수

	while (1) {		
		randomNum = rand() % 900 + 100; // 랜덤한 3자리수 생성

		bool same = false; // 모든 수가 다를 경우 true를 갖는 변수

		// TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성
        same = checkNum(randomNum);


		if (same == true) {
			break;
		}
	}

	int turn = 0;
	while (1) {
		cout << turn + 1 << "번째 시도입니다. " << endl;

		int userNumber; // 사용자가 입력한 세자리수 저장 변수
		int guessFirst; // 추측한 숫자의 첫번째 자리수
		int guessSecond; // 추측한 숫자의 두번째 자리수
		int guessThird; // 추측한 숫자의 세번째 자리수


		// 사용자에게 세자리 수를 입력받는 코드 블록
		while (1) {
			cout << "세자리 수를 입력해주세요: ";
			cin >> userNumber;

			bool same = false; // 모든 수가 다를 경우 true를 갖는 변수
			// TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성
            same = checkNum(userNumber); // 올바른 숫자를 입력하면  true를 반환
            if (!same){
                cout << "입력한 숫자에 중복이 있습니다. 다시 입력하세요." << endl;
				continue;
            }

			if (to_string(userNumber).length() != 3) {
				cout << "입력된 숫자가 3자리 수가 아닙니다. 다시 입력하세요." << endl;
				continue;
			}

			if (same == true) {
				break;
			}
		}


		int strike = 0; // 스트라이크 갯수를 저장하는 변수
		int ball = 0; // 볼 갯수를 저장하는 변수


		// TODO 2: 정답과 추측한 숫자의 자릿수와 숫자를 비교하며 힌트를 주기 위한 코드블록 작성
		hint(userNumber,randomNum, strike, ball);
        
		

		cout << userNumber << "의 결과 : " << strike << " 스트라이크, " << ball << "볼 입니다." << endl;
		
		if (strike == 3) {
			cout << "정답을 맞췄습니다. 축하합니다.";
			break;
		}

		turn += 1;
	}

	return 0;
}