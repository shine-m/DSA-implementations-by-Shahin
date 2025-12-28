#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
#define FAST_IO                  \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
#define PRECISION cout << setprecision(12);
#ifdef _WIN32
#define CLEAR_SCREEN system("cls");
#endif
#define TwoLineVerticalSpace cout << ln << ln;
#define where(condition, true_value, false_value) ((condition) ? true_value : false_value)
using ll = long long;

class node
{
public:
    int val;
    node *next;
    node(int val)
    {
        this->val = val;
        next = nullptr;
    }
};
class singlyList
{

    node *head;

public:
    singlyList()
    {
        head = nullptr;
    }

    void insert(int val)
    {

        node *newnode = new node(val);
        if (head == nullptr)
        {
            head = newnode;
            return;
        }
        node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    void display()
    {
        cout << "displaying : ";
        node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->val;
            if (temp->next != nullptr)
                cout << " => ";
            else
                cout << ln;
            temp = temp->next;
        }
    }
    void update(int currentVal, int updatedVal)
    {

        node *temp = head;
        while (temp != nullptr)
        {
            if (temp->val == currentVal)
            {
                temp->val = updatedVal;
                return;
            }
            temp = temp->next;
        }
        cout << "did not find value to update\n";
    }
    void deleteBack()
    {
        if (head == nullptr || head->next == nullptr)
        {
            head = nullptr;
            return;
        }
        node *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = nullptr;
    }
};
int main()
{
    CLEAR_SCREEN;
    TwoLineVerticalSpace;

    singlyList list;
    list.insert(8);
    list.insert(0);
    list.insert(8);
    list.insert(4);

    list.display();
    list.update(4, 6);
    list.display();

    list.deleteBack();
    list.display();

    TwoLineVerticalSpace;
    return 0;
}