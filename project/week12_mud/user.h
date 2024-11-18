#include <iostream>
class User
{
private:
    int hp;
    int itemCnt;

public:
    User();
    void DecreaseHP(int dec_hp);
    void IncreaseHP(int inc_hp);
    void incItemCnt();
    void decItemCnt();
    int GetHP();

    friend std::ostream & operator<<(std::ostream &os, const User &u){ // 멤버함수 불가능
        os << "현재 HP는 {" << u.hp<< "} 이고, 먹은 아이템은 총 {" << u.itemCnt << "} 개 입니다" << std::endl;
        return os;
    }
    
};