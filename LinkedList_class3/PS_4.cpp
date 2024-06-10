#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->next = NULL;
    }
    Node(int _data)
    {
        this->data = _data;
        this->next = NULL;
    }
};

void printLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data;
        if (temp->next)
            cout << "->";
        temp = temp->next;
    }
    cout << endl;
}

int printNN(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp)
    {
        count += 1;
        temp = temp->next;
    }
    return count;
}

void insertAtHead(Node *&head, int _data)
{
    Node *temp = new Node(_data);
    temp->next = head;
    head = temp;
    return;
}

void insertAtTail(Node *&head, int _data)
{
    Node *nn = new Node(_data);
    if (head == NULL)
    {
        head = nn;
    }
    else
    {
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = nn;
    }
    return;
}

void insertAtPosition(Node *&head, int _data, int position)
{
    int size = printNN(head);
    if (position <= 1)
    {
        insertAtHead(head, _data);
    }
    else if (position >= size + 1)
    {
        insertAtTail(head, _data);
    }
    else
    {
        Node *nn = new Node(_data);
        Node *curr = head;
        Node *prev = NULL;

        while (position != 1)
        {
            prev = curr;
            curr = curr->next;
            position--;
        }
        prev->next = nn;
        nn->next = curr;
    }
    return;
}

void reverseLL(Node *&head){
    Node*curr = head, *prev=NULL, *temp;
    while (curr)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
    return;
    
}

Node* returnMiddle(Node* head){
    Node* fast = head, *slow = head;
    while (fast->next)
    {
        fast = fast->next;
        if (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
    }
    return slow;
}

// bool checkPalindrome(Node *head){
//     Node* middle = returnMiddle(head);
//     reverseLL(middle);
//     Node* first = head, *second = middle;
//     while (first)
//     {
//         if (first->data != second->data)
//         {
//             return false;
//             break;
//         }
//         first = first->next;
//         second = second->next;
        
//     }
//     return true;
// }

bool checkPalindrome(Node *head){
    if (!head || !head->next) {
        return true;
    }
    
    Node* middle = returnMiddle(head);
    Node* secondHalf = middle->next;
    reverseLL(secondHalf);
    
    Node* first = head;
    Node* second = secondHalf;
    bool isPalindrome = true;
    while (second) // only need to check till second half
    {
        if (first->data != second->data)
        {
            isPalindrome = false;
            break;
        }
        first = first->next;
        second = second->next;
    }
    
    // Restore the original list
    reverseLL(secondHalf);
    middle->next = secondHalf;

    
    return isPalindrome;
}

int main()
{
    Node *head = NULL; // Initialize head as NULL
    insertAtPosition(head, 1, 1);
    insertAtPosition(head, 2, 2);
    insertAtPosition(head, 3, 3);
    insertAtPosition(head, 3, 4);
    insertAtPosition(head, 2, 5);
    insertAtPosition(head, 1, 6);
    printLL(head);
    cout << checkPalindrome(head) << endl;
    
    
}