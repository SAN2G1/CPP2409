#include <iostream>
using namespace std;
class RemoteControl {
    public:
        virtual void TurnON() = 0;
        virtual void TurnOFF() = 0;
};

class Television : public RemoteControl{
    void TurnON(){
        cout << "TV를 켭니다." <<endl;
    }
    void TurnOFF(){
        cout << "TV를 끕니다." <<endl;
    }
};

class Refrigerator : public RemoteControl{
    void TurnON(){
        cout << "냉장고를 켭니다." <<endl;
    }
    void TurnOFF(){
        cout << "냉장고를 끕니다." <<endl;
    }
};

int main(){
    RemoteControl* remoteTV = new Television();
    remoteTV -> TurnON();
    remoteTV -> TurnOFF();

    RemoteControl* remoteRefrigerator = new Refrigerator();
    remoteRefrigerator -> TurnON();
    remoteRefrigerator -> TurnOFF();

    delete remoteRefrigerator, remoteTV;
    return 0;
}