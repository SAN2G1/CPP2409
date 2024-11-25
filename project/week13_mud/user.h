#pragma once
#include <iostream>
class User
{
protected:
    int hp;
    int item_cnt;
    char icon;

public:
    int x_point;
    int y_point;
    User(char icon = 'U', int x = 0, int y = 0);
    virtual void DecreaseHp(int dec_hp) = 0;
    virtual void IncreaseHp(int inc_hp) = 0;
    virtual void IncItemCnt() = 0;
    virtual void DecItemCnt() = 0;
    virtual int GetHp() = 0;
    virtual char GetIcon() = 0;
    virtual void DoAttak() = 0;
    friend std::ostream &operator<<(std::ostream &os, const User &u)
    {
        os << "현재 HP는 {" << u.hp << "} 이고, 먹은 아이템은 총 {" << u.item_cnt << "} 개 입니다" << std::endl;
        return os;
    }
};