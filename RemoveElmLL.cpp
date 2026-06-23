#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

ListNode* removeElements(ListNode* head, int val) {
    ListNode dummy(0);
    dummy.next = head;

    ListNode* curr = &dummy;

    while (curr->next) {
        if (curr->next->val == val)
            curr->next = curr->next->next;
        else
            curr = curr->next;
    }

    return dummy.next;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next)
            cout << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        ListNode* node = new ListNode(x);

        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    int val;
    cin >> val;

    head = removeElements(head, val);

    printList(head);

    return 0;
}