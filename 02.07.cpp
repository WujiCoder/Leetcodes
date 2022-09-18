#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* dummyNodeA = new ListNode(0);
        dummyNodeA -> next = headA;
        ListNode* dummyNodeB = new ListNode(0);
        dummyNodeB -> next = headB;
        ListNode* curNodeA = dummyNodeA;
        ListNode* curNodeB = dummyNodeB;

        int sizeA = 0, sizeB = 0;
        while (curNodeA -> next != nullptr) {
            sizeA++;
            curNodeA = curNodeA -> next;
        }
        while (curNodeB -> next != nullptr) {
            sizeB++;
            curNodeB = curNodeB -> next;
        }
        curNodeA = dummyNodeA;
        curNodeB = dummyNodeB;
        int diff = sizeA - sizeB;
        if (diff > 0) {
            while (diff--) {
                curNodeA = curNodeA -> next;

            }
        }
        else {
            diff = abs(diff);
            while (diff--) {
                curNodeB = curNodeB -> next;
            }
        }

        while (curNodeA != nullptr && curNodeB != nullptr) {
            if (curNodeA == curNodeB) {
                return curNodeA;
            }

            curNodeA = curNodeA -> next;
            curNodeB = curNodeB -> next;
        }
        return nullptr;

    }
};