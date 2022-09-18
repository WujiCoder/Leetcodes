// 难度： 中等
// 题目描述：两两交换链表中的节点，返回头节点（注意不可以修改节点内部值） 。
// url: https://leetcode.cn/problems/swap-nodes-in-pairs/

 struct ListNode {
     int val;
     ListNode* next;
     ListNode(): val(0), next(nullptr) {}
     ListNode(int x): val(x), next(nullptr) {}
     ListNode(int x, ListNode* next): val(x), next(next) {}
 };
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* curNode = dummyHead;

        while(curNode -> next != nullptr && curNode -> next -> next != nullptr) {
            ListNode* frontNode = curNode -> next;
            ListNode* backNode = curNode -> next -> next;
            curNode -> next = backNode;
            frontNode -> next = backNode -> next;
            backNode -> next = frontNode;
            curNode = frontNode;

        }
        return dummyHead -> next;
    }
};