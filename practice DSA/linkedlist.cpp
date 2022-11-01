#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node *next;

        node(int d)
        {
            data = d;
            next = NULL;
        }
};

void insertAtTail(node *&head, int data)
{
    node *n = new node(data);

    if( head == NULL )
    {
        head = n;
        return ;
    }

    node *temp = head;
    while( temp->next != NULL )
    {
        temp = temp->next;
    }
    temp->next = n;
}

void deleteLastNode(node *head)
{
    if( head == NULL )
    {
        cout<<"Empty Linked List."<<endl;
        return;
    }
    if( head->next == NULL )
    {
        // free(head);
        cout<<"The list has only one node, can't be empty.";
        return;
    }

    node *p = head;
    node *q = head->next;

    while( q->next != NULL )
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
}

void deleteFirstNode(node *head)
{
    node *p = head;
    head = head->next;
    free(p);
}

// reverse the linked list
void reverse(node *head)
{
    node *p = head;
    node *q = NULL;
    node *r = NULL;

    while( p != NULL )
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}

void display(node *head)
{
    node *temp = head;
    while( temp != NULL )
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    node *main = NULL;


    insertAtTail(main, 10);
    insertAtTail(main, 20);
    insertAtTail(main, 30);
    insertAtTail(main, 40);

    display(main);

    deleteLastNode(main);

    display(main);

    deleteFirstNode(main);

    display(main);

    reverse(main);

    display(main);
    return 0;
}