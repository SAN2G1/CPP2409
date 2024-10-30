#include <iostream>
using namespace std;
class Rectangle {
public:
int width, height;
int CalcArea() {
return width * height;
}
};
int main() {
Rectangle obj;
Rectangle obj2;
obj.width = 3;
obj.height = 4;
obj2.width = 5;
obj2.height = 6;
int area = obj.CalcArea();
cout << "obj사각형의 넒이: " << area << endl;
cout << "obj2사각형의 넒이: " << obj2.CalcArea()<< endl;

return 0;
}