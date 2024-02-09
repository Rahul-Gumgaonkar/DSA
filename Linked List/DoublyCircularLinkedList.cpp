#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data) : data(data), prev(nullptr), next(nullptr) {}
    ~Node()
    {
        // Recursively delete nodes
        if (next != nullptr)
        {
            delete next;
        }
    }
};

void insertAtSpecificPosition(Node *&tail, int element, int data)
{
    if (tail == nullptr)
    {
        tail = new Node(data);
        tail->next = tail;
        tail->prev = tail;
    }
    else
    {
        Node *temp = tail;
        do
        {
            if (temp->data == element)
            {
                break;
            }
            temp = temp->next;
        } while (temp != tail);

        Node *newnode = new Node(data);
        newnode->next = temp->next;
        newnode->next->prev = newnode;
        newnode->prev = temp;
        temp->next = newnode;
    }
}

void deleteSpecificElement(Node *&tail, int element)
{
    if (tail == nullptr)
    {
        cout << "Linked List is Empty" << endl;
        return;
    }

    Node *current = tail->next; // Start from the first node
    while (current != tail)
    {
        if (current->data == element)
        {
            // Adjust pointers to bypass the current node
            current->prev->next = current->next;
            current->next->prev = current->prev;
            // If the tail is deleted, update the tail
            if (current == tail)
            {
                tail = current->prev;
            }
            current->next = nullptr;
            current->prev = nullptr;
            delete current; // Free memory
            return;
        }
        current = current->next;
    }

    // If the element is not found
    cout << "Element " << element << " not found in the list" << endl;
}

void printElements(Node *tail)
{
    if (tail == nullptr)
    {
        cout << "List is Empty" << endl;
        return;
    }

    Node *temp = tail->next;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << endl;
}

int main()
{
    Node *tail = nullptr;
    insertAtSpecificPosition(tail, 3, 5);
    insertAtSpecificPosition(tail, 4, 3);
    insertAtSpecificPosition(tail, 6, 4);
    insertAtSpecificPosition(tail, 5, 4);
    printElements(tail);
    cout << "Tail data: " << tail->data << endl;

    deleteSpecificElement(tail, 3);
    deleteSpecificElement(tail, 4);
    printElements(tail);

    delete tail; // Free memory of the entire list
    return 0;
}
