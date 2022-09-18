
// 难度： 简单
// 题目描述：链表实现 。
// url: https://leetcode.cn/problems/design-linked-list/

struct LinkedNode {
    int val;
    LinkedNode * next;
    // NULL与nullptr区别：
    // NULL在C++中实际代表的是0，因此在进行指针的初始化的时可能会报错，此时应该用nullptr。
    LinkedNode(): val(0), next(nullptr) {}
    LinkedNode(int x): val(x), next(nullptr) {}
    LinkedNode(int x, LinkedNode* next): val(x), next(next) {}
};

class MyLinkedList {
public:
    MyLinkedList() {
        head = new LinkedNode(0);
        size = 0;
    }

    int get(int index) {
        if (index > size - 1 || index < 0) return -1;

        LinkedNode* curNode = head -> next;
        while (index--) {
            curNode = curNode -> next;
        }
        return curNode -> val;

    }

    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        newNode -> next = head -> next;
        head -> next = newNode;
        size++;
    }

    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* curNode = head;
        while(curNode -> next != nullptr) {
            curNode = curNode -> next;
        }
        curNode -> next = newNode;
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0) {
            addAtHead(val);
            return;
        }
        if (index > size) return;

        LinkedNode* curNode = head;
        LinkedNode* newNode = new LinkedNode(val);
        while (index--) {
            curNode = curNode -> next;
        }
        newNode -> next = curNode -> next;
        curNode -> next = newNode;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        LinkedNode* curNode = head;
        while (index--) {
            curNode = curNode -> next;
        }
        LinkedNode* tmp = curNode -> next;
        curNode -> next = tmp -> next;
        delete tmp;
        size--;
    }
private:
    int size;
    LinkedNode* head;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

