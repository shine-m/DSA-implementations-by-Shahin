#include <bits/stdc++.h>
using namespace std;
#define ln "\n"

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {} // here in this code only this constructor has been used
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

    ListNode *slider, *head = new ListNode(1);
    slider = head;

    slider->next = new ListNode(2);
    slider = slider->next;
    slider->next = new ListNode(3);
    slider = slider->next;
    slider->next = new ListNode(4);

    slider = head;
    while (slider != nullptr)
    {
        cout << slider->val << ln;
        slider = slider->next;
    }

    return 0;
}