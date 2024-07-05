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

bool hasCycle(Node *head)
{
    Node *fast = head, *slow = head;
    while (fast)
    {
        fast = fast->next;
        if (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if (fast == slow)
        {
            return true;
            break;
        }
    }
    return false;
}

Node *detectCycle(Node *head) {
        Node* fast = head;
        Node* slow = head;
        while(fast){
            fast = fast->next;
            if(fast){
                fast = fast->next;
                slow = slow->next;
            }
            if(fast == slow){
                break;
            }
        }
        if(fast==NULL){
            return NULL;
        }
        else{
            slow = head;
            while(fast!=slow){
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }

void removeLoop(Node *head){
    Node* fast = head;
        Node* slow = head;
        while(fast){
            fast = fast->next;
            if(fast){
                fast = fast->next;
                slow = slow->next;
            }
            if(fast == slow){
                break;
            }
        }
        if(fast==NULL){
            return;
        }
        else{
            slow = head;
            while(fast!=slow){
                fast = fast->next;
                slow = slow->next;
            }
        }

        Node*temp = slow;
        while (temp->next!=slow)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        return;
}

int main(){
    Node* head = NULL;
    insertAtPosition(head, 10, 1);
    insertAtPosition(head, 20, 2);
    insertAtPosition(head, 30, 3);
    insertAtPosition(head, 40, 4);
    insertAtPosition(head, 50, 5);
    insertAtPosition(head, 60, 6);
    insertAtPosition(head, 70, 7);
    head->next->next->next->next->next->next->next = head->next;


    cout << (hasCycle(head) ? "Cycle detected" : "No cycle detected") << endl;
    Node* startofLoop = new Node(detectCycle(head)->data);
    startofLoop->next = NULL;
    printLL(startofLoop);

    removeLoop(head);
    cout << (hasCycle(head) ? "Cycle detected" : "No cycle detected") << endl;
    printLL(head);

    // Free the list (to avoid memory leaks in real use, but here it will not be reached)
   
    
    return 0;
}
