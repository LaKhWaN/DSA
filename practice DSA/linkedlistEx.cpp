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

void deleteNode(node *head, int ele)
{
    node *p = head;
    node *q = p->next;

    while( q->data != ele )
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
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
    // deleteLastNode(main);

    // display(main);
    deleteFirstNode(main);
    display(main);
    insertAtTail(main, 50);
    display(main);
    deleteNode(main, 30);
    display(main);
    // display(main);
    // do{
    //     cout<<"**==========================================**"<<endl;
    //     int choice;
    //     cout<<"1. Insert Node at Tail\n2. Delete last node\n3. Display Node\n4. Delete first node\nEnter choice: ";
    //     cin>>choice;
    //     if( choice == 1 )
    //     {
    //         int data;
    //         cout<<"Enter data to be inserted: ";
    //         cin>>data;
    //         insertAtTail(main, data);
    //         cout<<"After inserting:: "<<endl;
    //         display(main);
    //     }
    //     else if( choice == 2 )
    //     {
    //         deleteLastNode(main);
    //     }
    //     else if( choice == 3 )
    //     {
    //         display(main);
    //     }
    //     else if( choice == 4 )
    //     {
    //         deleteFirstNode(main);
    //     }
    //     else
    //     {
    //         cout<<"Exiting!"<<endl;
    //         return 0;
    //     }
    // } while( true );
    return 0;
}


















































































































































































































































































































































































































































































































































































































































































































































































































































































