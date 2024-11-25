#pragma once
#include <iostream>
class User
{
public:
    int hp;
    int item_cnt;
    char icon ;

    int x_point ;
    int y_point ;
    User(char icon = 'U', int x = 0, int y = 0);
    virtual void DecreaseHp(int dec_hp);
    virtual void IncreaseHp(int inc_hp);
    virtual void IncItemCnt();
    virtual void DecItemCnt();
    virtual int GetHp();
    virtual char GetIcon();
    virtual void DoAttak();
    friend std::ostream & operator<<(std::ostream &os, const User &u){ 
        os << "현재 HP는 {" << u.hp<< "} 이고, 먹은 아이템은 총 {" << u.item_cnt << "} 개 입니다" << std::endl;
        return os;
    }
    virtual ~User() {} // 가상 소멸자 추가
};