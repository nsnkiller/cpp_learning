#include <map>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* cur = head;
    int i = 0;
    map<int, ListNode*> imap;
    while (cur != nullptr){
        imap[++i] = cur;
        cur = cur->next;
    }
    if (i==n){
        return head->next;
    }
    imap[i-n]->next = imap[i-n+2];
    delete imap[i-n+1];
    return head;
}

int main() {
    // Example usage
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    int n = 2; // Remove the 2nd node from the end

    ListNode* result = removeNthFromEnd(head, n);

    // Print the result
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    head = new ListNode(1);
    n = 1; // Remove the 1st node from the end
    result = removeNthFromEnd(head, n);
    if (result == nullptr) {
        cout << "List is empty after removal." << endl;
    } else {
        while (result != nullptr) {
            cout << result->val << " ";
            result = result->next;
        }
        cout << endl;
    }

    // Clean up memory (not shown here for brevity)
    return 0;
}   