
# include <iostream>
using namespace std;

struct LinkNode {
    int val;
    LinkNode *next;
    LinkNode() : val(0), next(nullptr) {}
    LinkNode(int x) : val(x), next(nullptr) {}
    LinkNode(int x, LinkNode *next) : val(x), next(next) {}
};

class Solution {
public:
    LinkNode* removeElements(LinkNode* head, int val) {
        LinkNode* headNode = new LinkNode(0);
        headNode -> next = head;
        LinkNode* curNode = headNode;
        while(curNode -> next != NULL) {
            if (curNode -> next -> val == val){
                LinkNode* tmp = curNode -> next;
                curNode -> next = curNode -> next -> next;
                delete tmp;
            }
            else {
                curNode = curNode -> next;
            }

        }
        head = headNode -> next;
        delete headNode;
        return head;
    }
};