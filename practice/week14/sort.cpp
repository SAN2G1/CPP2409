#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    vector<int> data = {5, 2, 4, 3, 6, 7, 9, 0, 1, 3};
    sort(data.begin(), data.end());
    for (int n : data)
    {
        cout << n << ' ';
    }
    cout << '\n';
    return 0;
}