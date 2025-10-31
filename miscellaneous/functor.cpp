#include <bits/stdc++.h>
using namespace std;
#define swap(a, b) a = a + b - (b = a);
#define ln "\n"
#define where(condition, true_value, false_value) ((condition) ? true_value : false_value)

class mathematics
{

public:
    mathematics()
    {
        a = 6;
    }
    int a;
    size_t operator()(int a, int b) const
    {
        return a + b;
    }
};
int main()
{
    system("cls");
    cout << ln << ln;

    mathematics add;
    cout << add(4, 5); // using as function object
    cout << ln;

    cout << add.a;

    cout << ln << ln << ln;
    return 0;
}