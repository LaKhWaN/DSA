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

void deleteFirstNode(node *&head)
{
    node *p = head;
    head = head->next;
    free(p);
}

void rev(node *&head)
{
    node *prev = NULL;
    node *curr = head;
    node *nex = head->next;

    while( curr != NULL )
    {
        curr->next = prev;
        prev = curr;
        curr = nex;
        if( nex != NULL )
            nex = nex->next;
    }
    head = prev;
}

void searchNode(node *head, int data)
{
    node *temp = head;

    int i=0, flag=0;
    while( temp != NULL)
    {
        if( temp->data == data )
        {
            flag = 1;
            cout<<"Element found at "<<i<<" index."<<endl;
            break;
        }
        i++;
        temp = temp->next;
    }
    if( !flag ) cout<<"No element found in linked list."<<endl;

    return; 
}

void updateNode(node *head, int index, int d)
{
    node *temp = head;

    for( int i=0; i<index; i++)
    {
        temp = temp->next;
    }
    temp->data = d;
}

void sort(node *head)
{
    node *current = head;
    node *index   = NULL;

    int data;

    while( current != NULL )
    {
        index = current->next;

        while( index != NULL )
        {
            if( current->data > index->data )
            {
                data = current->data;
                current->data = index->data;
                index->data = data;
            }

            index = index->next;
        }

        current = current->next;
    }
}
void display(node *head)
{
    node *temp = head;
    while( temp != NULL )
    {
        cout<<temp->data<<", ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    node *main = NULL;

    // 1. Inserting a node at the end of the linked list.
    cout<<"Inserting a node at the end of the linked list."<<endl;
    insertAtTail(main, 10);
    insertAtTail(main, 20);
    insertAtTail(main, 30);
    insertAtTail(main, 40);
    display(main);

    // 3. Deleting the last node of the linked list.
    cout<<"Deleting the last node of the linked list."<<endl;
    deleteLastNode(main);
    display(main);

    // 4. Deleting the first node of the linked list.
    cout<<"Deleting the first node of the linked list."<<endl;
    deleteFirstNode(main);
    display(main);

    // 5. Inserting a node at the end of the linked list.
    cout<<"Inserting a node at the end of the linked list."<<endl;
    insertAtTail(main, 50);
    display(main);

    // 6. Reversing the linked list.
    cout<<"Reversing the linked list."<<endl;
    rev(main);
    display(main);

    // 7. Searching an element in the linked list.
    cout<<"Searching an element in the linked list."<<endl;
    searchNode(main, 50);
    searchNode(main, 100);

    // 8. Updating a node in the linked list.
    cout<<"Updating a node in the linked list."<<endl;
    updateNode(main, 2, 100);
    display(main);

    // 9. Sorting the linked list.
    cout<<"Sorting the linked list."<<endl;
    sort(main);
    display(main);

    return 0;
}