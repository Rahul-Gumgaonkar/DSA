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
        delete next;

        cout << "Delted Element is : " << data << endl;
    }
};

void insertElement(Node *&tail, int data, int element)
{
    if (tail == NULL)
    {
        Node *newnode = new Node(data);
        tail = newnode;
        newnode->next = tail;
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
        temp->next = newnode;
    }
}

void deleteElement(Node *&tail, int element)
{
    if (tail == NULL)
    {
        cout << "Linked list is Empty" << endl;
    }
    else
    {
        // assuming that element is present
        Node *left = tail;
        Node *curr = left->next;
        while (curr->data != element)
        {
            left = curr;
            curr = curr->next;
        }
        // 1Node linked list
        if (left == curr)
        {
            tail = NULL;
        }
        // >=2 Node linked list
        else if (tail == curr)
        {
            tail = left;
        }
        left->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void printElement(Node *&tail)
{
    Node *temp = tail;

    if (tail == NULL)
    {
        cout << "List is Empty" << endl;
        return;
    }

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
}
int main()
{

    Node *tail = NULL;
    insertElement(tail, 3, 5);
    insertElement(tail, 4, 3);
    // insertElement(tail, 6, 4);
    // insertElement(tail, 5, 4);
    printElement(tail);
    cout << endl;
    cout << tail->data << endl;

    cout << endl;

    deleteElement(tail, 3);
    printElement(tail);

    return 0;
}