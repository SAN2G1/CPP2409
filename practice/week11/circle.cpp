#include <iostream>
using namespace std;
class Circle
{
private:
    int radius;

public:
    Circle() { radius = 10; }
    ~Circle() {}
    void SetRadius(int radius) { this->radius = radius; }
    int GetRadius() const { return radius; }
};
int main()
{
    Circle *p = new Circle();
    const Circle *pConstObj = new Circle(); // const가 어디에 붙는지에 따라서 상수 취급을 뭘로 할지가 갈린다.
    Circle *const pConstPtr = new Circle(); // 포인터 옆 const는 주소를 바꾸지 않는것이고 위에 것은 객체가 const이다.
    cout << "pRect->radius: " << p->GetRadius() << endl;
    cout << "pConstObj->radius: " << pConstObj->GetRadius() << endl;
    cout << "pConstPtr->radius: " << pConstPtr->GetRadius() << endl
         << endl;
    p->SetRadius(30);
    //pConstObj->SetRadius(30);
    pConstPtr->SetRadius(30);
    cout << "pRect->radius: " << p->GetRadius() << endl;
    cout << "pConstObj->radius: " << pConstObj->GetRadius() << endl;
    cout << "pConstPtr->radius: " << pConstPtr->GetRadius() << endl;
    return 0;
}