#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
typedef long long ll;
#define loop(n) for (int i = 0; i < n; i++)
#define clearterminal system("cls")

class Solution
{
public:
    unordered_set<int> signatures;
    bool isHappy(int n)
    {
        int temp = n;

        int sum = 0;

        while (temp > 0)
        {
            sum += ((temp % 10) * (temp % 10));
            temp /= 10;
        }
        if (sum == 1)
        {
            return true;
        }
        int prev = signatures.size();
        signatures.insert(sum);
        if (prev == signatures.size())
        {
            return false;
        }
        return this->isHappy(sum);
    }
};
int main()
{
    clearterminal;

    Solution ob;
    cout << ob.isHappy(10);

    return 0;
}
