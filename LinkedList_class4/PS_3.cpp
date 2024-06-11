// Add Two LinkedList

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

void reverseL(Node *&head)
{
    Node *curr = head, *prev = NULL;
    Node *temp = NULL;
    while (curr)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
}

void addTwoLL(Node *&num1, Node *&num2)
{
    reverseL(num1);
    reverseL(num2);
    Node *first = num1, *sec = num2; 
    int sum = 0;
    int carry = 0;
    int sizenum1 = printNN(first);
    int sizenum2 = printNN(sec);
    Node* prev=NULL;
    while (first || sec)
    {
        sum = 0;
        if (first)
        {
            sum += first->data;
        }
        if (sec)
        {
            sum += sec->data;
        }
        sum += carry;
        carry = sum/10;
        sum %= 10;
        if (sizenum1>=sizenum2)
        {
            first->data = sum;
            prev = first;
            first = first->next;
            if (sec)
            {
                sec = sec->next;
            }
            
        }
        else{
            sec->data = sum; 
            prev = sec;
            sec = sec->next;
            if (first)
            {
                sec = sec->next;
            }
            
        }
    }
    if (sizenum1>=sizenum2 && carry)
    {
        prev->next = new Node(carry);
    }
    else if(sizenum2>=sizenum1 && carry){
        prev->next = new Node(carry);
    }
    reverseL(num1);
    reverseL(num2);
    
}

int main()
{

    Node *head = new Node(9);
    head->next = new Node(9);
    head->next->next = new Node(9);
    head->next->next->next = new Node(9);

    Node *head1 = new Node(1);
    // head1->next = new Node(2);
    // head1->next->next = new Node(3);

    printLL(head);
    printLL(head1);
    addTwoLL(head, head1);
    printLL(head);

}