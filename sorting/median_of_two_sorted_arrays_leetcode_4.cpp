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

        vector<int> aggregate(nums1.size() + nums2.size());
        int n1 = 0, n2 = 0;
        for (int i = 0; i <= aggregate.size() / 2; i++)
        {
            if (n1 == nums1.size())
            {
                while (n2 < nums2.size() && i <= aggregate.size() / 2)
                {
                    aggregate[i++] = nums2[n2++];
                }
                break;
            }
            if (n2 == nums2.size())
            {
                while (n1 < nums1.size() && i <= aggregate.size() / 2)
                {
                    aggregate[i++] = nums1[n1++];
                }
                break;
            }

            if (nums1[n1] > nums2[n2])
            {
                aggregate[i] = nums2[n2++];
            }
            else
                aggregate[i] = nums1[n1++];
        }
        if (aggregate.size() & 1)
        {
            return (aggregate[aggregate.size() / 2]);
        }
        else
            return (aggregate[aggregate.size() / 2] + aggregate[(aggregate.size() - 1) / 2]) / 2.0;
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