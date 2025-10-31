#include <bits/stdc++.h>
using namespace std;
#define swap(a, b) a = a + b - (b = a);
#define ln "\n"

// the idea behind this is when bitwise and is multiplied by 2, it gets left shihfted by 1 unit. so each 1 in the resultant string acts as the carry bit  gotten from bitwise summation of previous 2 bits . thus (a+b) = a^b + 2*(a&b)
int main()
{
    system("cls");
    cout << ln << ln;

    srand(0);
    for (int i = 0; i < 10; i++)
    {
        int a = rand() % 100, b = rand() % 100;
        cout << "a = " << a << "\tb = " << b << "\ta+b = " << a + b << ln;
        cout << "(a ^ b) = " << (a ^ b) << "\n"
             << "2 * (a & b) = " << 2 * (a & b) << ln << "a^b + 2*(a&b) = " << (a ^ b) + 2 * (a & b) << ln << ln;
    }

    cout << ln << ln << ln;
    cout << " decision : a^b + 2*(a&b) = a+b\n\n\n";
    return 0;
}