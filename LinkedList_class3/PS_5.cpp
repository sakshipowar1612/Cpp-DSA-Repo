#include <iostream>
#include <map>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;
    ListNode(int _data) : data(_data), next(nullptr) {}
};

bool hasCycle(ListNode* head) {
    if (!head || !head->next) {
        return false;
    }
    
    map<ListNode*, bool> table;
    ListNode* temp = head;
    while (temp) {
        if (table.find(temp) != table.end()) {
            return true;
        } else {
            table[temp] = true;
        }
        temp = temp->next;
    }
    return false;
}

int main() {
    // Create a linked list with a cycle
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = head->next; // Creating a cycle

    cout << (hasCycle(head) ? "Cycle detected" : "No cycle detected") << endl;

    // Free the list (to avoid memory leaks in real use, but here it will not be reached)
    head->next->next->next = nullptr; // Break the cycle first
    delete head->next->next;
    delete head->next;
    delete head;
    
    return 0;
}
