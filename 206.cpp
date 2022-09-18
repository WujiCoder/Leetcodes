// 难度： 简单
// 题目描述：链表反转 。
// url: https://leetcode.cn/problems/reverse-linked-list/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* preNode = nullptr;
        ListNode* curNode = head;
        ListNode* tmp;

        while(curNode != nullptr) {
            tmp = curNode -> next;
            curNode -> next = preNode;
            preNode = curNode;
            curNode = tmp ;
        }
        return preNode;

    }
};
