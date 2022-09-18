// 难度： 中等
// 题目描述：给定一个链表的头节点，返回链表开始入环的第一个节点。如果链表无还，则返回null。
// url: https://leetcode.cn/problems/linked-list-cycle-ii/

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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slowNode = head;
        ListNode* fastNode = head;
        while(fastNode != nullptr && fastNode -> next != nullptr) {
            slowNode = slowNode -> next;
            fastNode = fastNode -> next -> next;
            if (slowNode == fastNode) {
                ListNode* tmpNode = head;
                while (slowNode != tmpNode) {
                    slowNode = slowNode -> next;
                    tmpNode = tmpNode -> next;
                }
                return slowNode;
            };
        }
        return NULL;
    }
};
