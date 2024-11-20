#pragma once
#include <iostream>
class User
{
private:
    int hp;
    int item_cnt;
    char icon ;
public:
    int x_point ;
    int y_point ;
    User(char icon = 'U', int x = 0, int y = 0);
    void DecreaseHp(int dec_hp);
    void IncreaseHp(int inc_hp);
    void IncItemCnt();
    void DecItemCnt();
    int GetHp();
    char GetIcon();
    virtual void DoAttak();
    friend std::ostream & operator<<(std::ostream &os, const User &u){ 
        os << "현재 HP는 {" << u.hp<< "} 이고, 먹은 아이템은 총 {" << u.item_cnt << "} 개 입니다" << std::endl;
        return os;
    }
    virtual ~User() {} // 가상 소멸자 추가
};