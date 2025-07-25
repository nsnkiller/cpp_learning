#include <iostream>
using namespace std;    


struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = nullptr;
        ListNode* cur = nullptr;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr){
            int val = 0;
            val += carry;
            carry = 0;
            if (l1 != nullptr){
                val += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr){
                val += l2->val;
                l2 = l2->next;
            }
            carry = val/10;
            val = val%10;
            if (res == nullptr){
                res = new ListNode(val);
                cur = res;
            }else{
                cur->next = new ListNode(val);
                cur = cur->next;
            }
        }
        if (carry != 0){
            cur->next = new ListNode(carry);
        }
        return res;
}

int main() {
    // Example usage
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3))); // Represents 342
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4))); // Represents 465

    ListNode* result = addTwoNumbers(l1, l2);

    // Print the result
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    // Clean up memory (not shown here for brevity)
    delete l1->next->next; // Delete 3
    delete l1->next;        //Delete 4
    delete l1;             // Delete 2
    delete l2->next->next; // Delete 4
    delete l2->next;       // Delete 6
    delete l2;            // Delete 5
    return 0;
}   