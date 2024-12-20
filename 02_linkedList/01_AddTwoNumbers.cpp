#include <iostream>

// Definition for singly-linked list.
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
        ListNode *temp1, *temp2,*sumNode,*first;
        temp1 = l1, temp2 = l2;
        // variable = (condition) ? Expression2 : Expression3;

        // creating num
        int num1 = 0, num2 = 0, i = 0;
        while (temp1 != nullptr)
        {
            num1 += (temp1->val) * pow(10, i++);
            temp1 = temp1->next;
        }
        i = 0;
        while (temp2 != nullptr)
        {
            num2 += (temp2->val) * pow(10, i++);
            temp2 = temp2->next;
        }

        // adding to linked list
        first = 0;
        int sum = num1 + num2;
        sumNode = (ListNode *)malloc(sizeof(ListNode));
        sumNode->next = NULL;

        if (first != 0)
        {
            temp1->next = sumNode;
            temp1 = sumNode;
        }
        else
        {
            first = temp1 = sumNode;
        }
    }
};