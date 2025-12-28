#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
#define where(condition, true_value, false_value) ((condition) ? true_value : false_value)
#define FAST_IO                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
#define PRECISION cout << setprecision(12);
#ifdef _WIN32
#define ClearTerminal system("cls")
#endif
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {

        int n1, n2;
        n1 = n2 = 0;
        vector<int> augmented;
        while (n1 < nums1.size() && n2 < nums2.size())
        {

            if (nums1[n1] < nums2[n2])
                augmented.push_back(nums1[n1++]);
            else
                augmented.push_back(nums2[n2++]);
        }
        while (n1 < nums1.size())
        {
            augmented.push_back(nums1[n1++]);
        }
        while (n2 < nums2.size())
        {
            augmented.push_back(nums2[n2++]);
        }

        if (augmented.size() & 1)
            return augmented[augmented.size() / 2];

        return (augmented[augmented.size() / 2] +
                augmented[(augmented.size() - 1) / 2]) /
               2.0;
    }
};
int main()
{
    FAST_IO
    PRECISION
    ClearTerminal;
    cout << ln << ln;

    vector<int> v1 = {1, 2}, v2 = {3};
    Solution obj;
    cout << obj.findMedianSortedArrays(v1, v2);

    cout << ln << ln << ln;
    return 0;
}