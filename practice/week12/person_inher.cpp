#include <iostream>
using namespace std;
class Person
{
protected:
    string name; // 기본적으로private
    string address;


};
class Student : Person
{
public:
    void SetAddress(string add)
    {
        address = add;
    }
    string GetAddress()
    {
        return address;
    }
    void SetName(string name){this->name = name; }
    string GetName() {return this -> name;}
};

int main()
{
    Student obj;
    obj.SetName("상권") ;
    obj.SetAddress("서울시 종로구 1번지");
    cout << obj.GetAddress() << endl;
    cout << obj.GetName() << endl;

    return 0;
}