#include <bits/stdc++.h>
#define ln "\n"
typedef long long ll;
#define print(s) cout << s;
#define linegap cout << ln << ln;
#define loop(n) for (int i = 0; i < n; i++)
using namespace std;
class parameters
{
public:
    int length, price;
    parameters(int l, int p) : length(l), price(p) {}
};

int rod_cutting(vector<parameters> &v, int left, int n)
{
    return left;
}
int main()
{
    linegap

        vector<parameters>
            rod = {{1, 1}, {2, 3}, {3, 6}, {4, 7}};
    int size = rod.size();
    print("length - price" << ln);
    for (auto i : rod)
    {
        cout << i.length << " " << i.price << ln;
    }
    cout << ln;
    print("enter length of Rod\t") int total_length;
    cin >> total_length;
    print("maximum prifit\t" << rod_cutting(rod, total_length, size - 1) << ln)
        linegap return 0;
}