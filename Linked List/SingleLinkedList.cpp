#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        int val = this->data;

        // if (this->data != NULL)
        // {
        //     delete next;
        //     this->next = NULL;
        // }

        delete next;

        cout << "Memory free for node with data : " << val << endl;
    }
};

int findLength(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

// I want to insert a node right at the head of Linked List
void insertAtHead(Node *&head, Node *&tail, int data)
{
    // step1:
    Node *newnode = new Node(data);
    // If head and tail is empty
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        // Step2:
        newnode->next = head;
        // Step3:
        head = newnode;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    // Step1:
    Node *newnode = new Node(data);

    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        // Step2:
        tail->next = newnode;
        // Step3:
        tail = newnode;
    }
}

void insertAtSpecificPosition(Node *&head, Node *&tail, int data, int position)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    // If Position is 0
    if (position == 0)
    {
        insertAtHead(head, tail, data);
        return;
    }

    int len = findLength(head);

    // If Position is greater than tail or equal to tail
    if (position > len)
    {
        insertAtTail(head, tail, data);
        return;
    }

    int i = 1;
    Node *prev = head;
    while (i < position - 1)
    {
        prev = prev->next;
        i++;
    }

    Node *curr = prev->next;

    Node *newnode = new Node(data);

    newnode->next = curr;
    prev->next = newnode;
}

void deleteNode(Node *&head, Node *&tail, int position)
{
    // For Empty Linked List
    if (head == NULL)
    {
        cout << "Linked List is Empty" << endl;
    }

    // Delete first Node
    if (position == 1)
    {
        Node *prev = head;
        head = head->next;
        prev->next = NULL;
        delete prev;
        return;
    }

    // Delete Last Node
    int len = findLength(head);

    if (position > len)
    {
        cout << "Invalid Position" << endl;
        return;
    }

    if (len == position)
    {
        // find prev
        int i = 1;
        Node *prev = head;
        while (i < position - 1)
        {
            prev = prev->next;
            i++;
        }
        // step2:
        prev->next = NULL;
        // step3:
        Node *curr = prev->next;
        // step4:
        tail = prev;
        // step5:
        delete curr;
        return;
    }

    // Delete Middle Node

    // step  : find prev and curr
    int i = 1;
    Node *prev = head;
    while (i < position - 1)
    {
        prev = prev->next;
        i++;
    }
    Node *curr = prev->next;
    // step2:
    prev->next = curr->next;
    // step3:
    curr->next = NULL;
    // step4:
    delete curr;
}

void printLinkedList(Node *&head)
{
    if (head == NULL)
    {
        cout << "Linked List is Empty" << endl;
    }
    else
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
}

Node *reverse(Node *&prev, Node *&curr)
{
    // Base Case
    if (curr == NULL)
    {
        return prev;
    }

    // Eak Case Solve kar lo
    Node *forward = curr->next;
    curr->next = prev;

    return reverse(curr, forward);
}
int main()
{

    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    printLinkedList(head);
    cout << endl;
    cout << "head -> " << head->data << endl;
    cout << "tail -> " << tail->data << endl;

    insertAtTail(head, tail, 50);
    insertAtTail(head, tail, 60);
    insertAtTail(head, tail, 70);
    printLinkedList(head);
    cout << endl;
    cout << "head -> " << head->data << endl;
    cout << "tail -> " << tail->data << endl;

    // insertAtSpecificPosition(head, tail, 10, 0);
    // insertAtSpecificPosition(head, tail, 80, 4);
    // insertAtSpecificPosition(head, tail, 90, 2);
    insertAtSpecificPosition(head, tail, 100, 6);
    printLinkedList(head);
    cout << endl;
    cout << "head -> " << head->data << endl;
    cout << "tail -> " << tail->data << endl;

    deleteNode(head, tail, 2);
    printLinkedList(head);
    cout << endl;
    cout << "head -> " << head->data << endl;
    cout << "tail -> " << tail->data << endl;

    Node *prev = NULL;
    Node *curr = head;
    tail = head;
    head = reverse(prev, curr);
    printLinkedList(head);
    cout << endl;
    cout << "head -> " << head->data << endl;
    cout << "tail -> " << tail->data << endl;

    return 0;
}