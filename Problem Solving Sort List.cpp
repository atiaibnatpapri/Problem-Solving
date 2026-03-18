#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};


ListNode* sortList(ListNode* head) {

    if(head == NULL || head->next == NULL)
        return head;

    bool swapped;

    do {
        swapped = false;
        ListNode* temp = head;

        while(temp->next != NULL) {
            if(temp->val > temp->next->val) {

                int t = temp->val;
                temp->val = temp->next->val;
                temp->next->val = t;
                swapped = true;
            }
            temp = temp->next;
        }
    } while(swapped);

    return head;
}


void printList(ListNode* head) {
    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    int n, x;
    cin >> n;

    if(n == 0) {
        cout << "Empty list" << endl;
        return 0;
    }


    cin >> x;
    ListNode* head = new ListNode(x);
    ListNode* temp = head;

    for(int i = 1; i < n; i++) {
        cin >> x;
        temp->next = new ListNode(x);
        temp = temp->next;
    }

    cout << "Before Sorting: ";
    printList(head);

    head = sortList(head);

    cout << "After Sorting: ";
    printList(head);

    return 0;
}
