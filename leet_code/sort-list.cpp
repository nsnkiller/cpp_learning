#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* sortList(ListNode* head) 
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode* new_head = nullptr;
    while(head){
        if (new_head == nullptr){
            new_head = head;
            head = head->next;
            new_head->next = nullptr;
            
        }else{
            if (head->val < new_head->val){
                ListNode * tmp = head;
                head = head->next;
                tmp->next = new_head;
                new_head = tmp;
            }else{
                ListNode * curr = new_head;
                while (curr->next != nullptr && curr->next->val < head->val) {
                    curr = curr->next;
                }
                ListNode * tmp = head;
                head = head->next;
                tmp->next = curr->next;
                curr->next = tmp;
            }
        }
    }
    return new_head;
}

int main() {
    // Example usage
    ListNode* head = new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3))));
    
    ListNode* result = sortList(head);

    // Print the result
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    // Clean up memory (not shown here for brevity)
    return 0;
}   