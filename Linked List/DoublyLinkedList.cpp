#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node()
    {
        this->data = 0;
        this->next = NULL;
        this->prev = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node()
    {
        cout << "Deleted Value is : " << this->data;
        delete next;
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

void insertAtHead(Node *&head, Node *&tail, int data)
{
    Node *newnode = new Node(data);

    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *newnode = new Node(data);

    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    if (head == NULL)
    {
        Node *newnode = new Node(data);
        head = newnode;
        tail = newnode;
        return;
    }

    if (position == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }

    int len = findLength(head);

    if (position > len)
    {
        insertAtTail(head, tail, data);
        return;
    }

    Node *prevNode = head;

    int i = 1;
    while (i < position - 1)
    {
        prevNode = prevNode->next;
        i++;
    }

    Node *currNode = prevNode->next;

    Node *newnode = new Node(data);

    prevNode->next = newnode;
    newnode->prev = prevNode;
    newnode->next = currNode;
    currNode->prev = newnode;
}

void deleteFromPosition(Node *&head, Node *&tail, int position)
{

    // Empty Linked List
    if (head == NULL)
    {
        cout << "Linked List is Empty" << endl;
        return;
    }

    if (head->next == NULL)
    {
        Node *temp = head;
        head = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }

    int len = findLength(head);
    if (position > len)
    {
        cout << "Invalid Position" << endl;
        return;
    }

    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }

    if (position == len)
    {
        Node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;
        return;
    }

    int i = 1;
    Node *left = head;
    while (i < position - 1)
    {
        left = left->next;
        i++;
    }
    Node *curr = left->next;
    Node *right = curr->next;

    left->next = right;
    right->prev = left;
    curr->next = NULL;
    curr->prev = NULL;

    delete curr;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);
    // insertAtTail(head, tail, 60);
    // insertAtTail(head, tail, 70);

    printLinkedList(head);
    cout << endl;
    cout << "head -> " << head->data << endl;
    cout << "tail -> " << tail->data << endl;

    insertAtPosition(head, tail, 100, 7);
    printLinkedList(head);
    cout << endl;
    cout << "head -> " << head->data << endl;
    cout << "tail -> " << tail->data << endl;

    deleteFromPosition(head, tail, 1);
    cout << endl;
    printLinkedList(head);
    cout << endl;
    cout << "head -> " << head->data << endl;
    cout << "tail -> " << tail->data << endl;

    return 0;
}