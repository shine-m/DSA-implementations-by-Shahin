#include <bits/stdc++.h>
using namespace std;
#define ln "\n"

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *result, *forward;
        forward = result;
        int hand = 0;
        while (1)
        {

            ListNode(sum);
        }
    }
};
int main()
{
    cout << ln << ln;

    ListNode *l;
    l->val = 34;
    cout << l->val << " ";

    // code ta etokhon kaaj kore nai karon pointer declar kora hoile o memory cllocation hoy nai. tai ekahane new kewwork diye ekta memory allocation kore nite hobe

    ListNode *node = new ListNode(); // ei 2 line kaaj korbe na karon ager code gulo vul r executuion okhane e halt kore ase
    cout << node->val << " ";

    return 0;
}