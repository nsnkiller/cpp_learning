#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) 
{
    if (head == nullptr || head->next == nullptr){
        return head;
    }

    ListNode* res = head->next;

    head->next = swapPairs(res->next);
    res->next = head;
    return res;
}

int main() {
    // Example usage
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
    
    ListNode* result = swapPairs(head);

    // Print the result
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    // Clean up memory (not shown here for brevity)
    return 0;
}   