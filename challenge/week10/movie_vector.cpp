#include <iostream>
#include <vector>
using namespace std;
class Movie
{
public:
    string name;
    double rating;

    Movie()
    {
        name = "Null";
        rating = 0.0;
    }
    Movie(string name, double rating)
    {
        this->name = name;
        this->rating = rating;
    }
    void Print()
    {
        cout << name << " : " << rating << endl;
    }
};
int main(void)
{
    vector<Movie> objArray;

    objArray.push_back(Movie("바람과 함께 사라지다", 4.5));
    objArray.push_back(Movie("전우치", 4.3));
    objArray.push_back(Movie("고지전", 8.4));

    for (Movie m : objArray)
        m.Print();
    return 0;
}