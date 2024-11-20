#include "user.h"

User::User(char icon, int x, int y) : icon(icon), x_point(x), y_point(y) {
    hp = 20;
    item_cnt = 0;
}
void User::DecreaseHp(int dec_hp){
    hp -= dec_hp;
}
void User::IncreaseHp(int inc_hp){
    hp += inc_hp;
}
int User::GetHp(){
    return hp;
    }

void User::IncItemCnt(){
    ++item_cnt;
}
void User::DecItemCnt(){
    --item_cnt;
}

char User:: GetIcon(){
    return icon;
}

void User:: DoAttak(){
    std::cout << "공격합니다." << std::endl; 
}