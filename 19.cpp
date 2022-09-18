
// 难度： 中等
// 题目描述：删除链表的倒数第n个结点 。
// url: https://leetcode.cn/problems/remove-nth-node-from-end-of-list/


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyNode = new ListNode(0, head);
        ListNode* slowNode = dummyNode;
        ListNode* fastNode = dummyNode;

        ListNode* prevNode;
        while(--n) {
            fastNode = fastNode -> next;
        }

        while(fastNode -> next != nullptr) {
            prevNode = slowNode;
            fastNode = fastNode -> next;
            slowNode = slowNode -> next;
        }

        prevNode -> next = slowNode -> next;
        delete slowNode;
        return dummyNode -> next;

    }
};