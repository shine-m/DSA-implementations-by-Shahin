// https://leetcode.com/problems/add-two-numbers/submissions/1551134138/
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
    ListNode *addTwoNumbers(ListNode *list1, ListNode *list2)
    {

        ListNode *it1 = list1, *it2 = list2;

        int hand = 0;
        if (it1 != nullptr)
            hand += it1->val;
        if (it2 != nullptr)
            hand += it2->val;

        ListNode *slider, *result = new ListNode(hand % 10);
        hand /= 10;

        slider = result;
        list2 = list2->next;
        list1 = list1->next;

        while (1)
        {

            if (list1 != nullptr)
            {
                if (list2 != nullptr)
                {
                    slider->next = new ListNode((hand = hand + list1->val + list2->val) % 10);

                    list2 = list2->next;
                }
                else
                {

                    slider->next = new ListNode((hand = hand + list1->val) % 10);
                }
                list1 = list1->next;
            }
            else if (list2 != nullptr)
            {

                slider->next = new ListNode((hand = hand + list2->val) % 10);
                list2 = list2->next;
            }

            else
                break;
            hand /= 10;
            // list 1 and 2 ekhane update korsilam dekhe problem hoisilo , karon ekhane check kora hoy nai je list already sesh kina
            slider = slider->next;
        }
        if (hand)
            slider->next = new ListNode(hand);

        return result;
    }
};
int main()
{
    ListNode *list1 = new ListNode(9);
    int list1_elements = 7;

    ListNode *list2 = new ListNode(7);
    int list2_elements = 5;

    ListNode *it;

    // appointing values through loops in list 1
    // it = list1;
    // while (list1_elements--)
    // {

    //     it->next = new ListNode(list1_elements);
    //     it = it->next;
    // }

    // assigning values in list 2 through loop
    // it = list2;
    // while (list2_elements--)
    // {

    //     it->next = new ListNode(list2_elements);
    //     it = it->next;
    // }

    it = list1;

    while (it != nullptr)
    {

        cout << it->val << " ";
        it = it->next;
    }
    cout << ln;

    it = list2;

    while (it != nullptr)
    {

        cout << it->val << " ";
        it = it->next;
    }
    cout << ln;
    Solution ob;
    ListNode *traverse = ob.addTwoNumbers(list1, list2);

    it = traverse;

    while (it != nullptr)
    {

        cout << it->val << " ";
        it = it->next;
    }
    cout << ln;

    return 0;
}