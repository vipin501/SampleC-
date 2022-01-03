/* Class, Linked List, custom contaniner easy insertion but no random access for elements need to traverse*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int node_data) {
        this->data = node_data;
        this->next = nullptr;
    }
};

class LnkList
{
    Node* head, * tail;
public:
    LnkList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    ~LnkList()
    {
        Node* tmp = head;
        while (tmp) {
            Node* curr = tmp;
            tmp = tmp->next;
            delete curr;
        }
    }
    void InsertNode(int n_data);
    void PrintList();
};

void LnkList::InsertNode(int n_data)
{
    Node* tmp = new Node(n_data);

    if (!this->head) {
        this->head = tmp;
    }
    else {
        this->tail->next = tmp;
    }

    this->tail = tmp;
}

void LnkList::PrintList()
{
    Node* curr = head;
    while (curr != NULL)
    {
        cout << curr->data << endl;
        curr = curr->next;
    }
}

int main()
{
    LnkList* lst = new LnkList();
    lst->InsertNode(6);
    lst->InsertNode(14);
    lst->InsertNode(89);
    lst->InsertNode(45);
    lst->InsertNode(1);

    cout << "List contents as follow:" << endl;
    lst->PrintList();

    delete lst;
    return 0;
}