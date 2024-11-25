#include "user.h"

User::User(char icon, int x, int y) : icon(icon), x_point(x), y_point(y) {
    hp = 20;
    item_cnt = 0;
}
