#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
        int data;
        node* prev;
        node* next;

        node(int val)
        {
            data = val;
            prev = NULL;
            next = NULL;
        }
};

void insertAtTail(node* &head, int val)
{
    node* n = new node(val);
    node* temp = head;
    if(head == NULL)
    {
        head = n;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
        n->prev = temp;
    }
}

void insertAtHead(node* &head, int val)
{
    node* n = new node(val);
    
    if(head == NULL)
    {
        head = n;
        return;
    }
    n->next = head;
    head = n;
}

void insert(node* &head, int val, int posi)
{
    node* n = new node(val);
    node* temp = head;
    for(int i=0;i<posi-1;i++)
    {
        /* code */
        temp = temp->next;
    }
    n->next = temp->next;
    n->prev = temp;
    temp->next = n;
}

void deleteAtTail(node* &head)
{
    if(head == NULL)
        return;
    if(head->next == NULL)
    {
        delete head;
        return;
    }
    node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    delete temp;
}
void deleteHead(node* &head)
{
    if(head == NULL)
        return;
    if(head->next == NULL)
    {
        delete head;
        return;
    }
    node* temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
}
void deleteData(node* &head, int val)
{
    if(head == NULL)
        return;
    if(head->next == NULL)
    {
        deleteHead(head);
        return;
    }
    node* temp = head;
    node* temp1;
    while(temp->data != val)
    {
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next = temp->next;
    temp->next->prev = temp1;
    delete temp;
    
}
void deleteposi(node* &head, int posi)
{
    if(head == NULL)
        return;
    if(head->next == NULL)
    {
        deleteHead(head);
        return;
    }
    node* temp = head;
    node* temp1;
    int count = 1;
    while(temp->next != NULL)
    {
        count++;
        temp = temp->next;
    }
    if(count == posi)
    {
        deleteAtTail(head);
        return;
    }
    for(int i=0;i<posi-1;i++)
    {
        temp1 = temp;
        temp = temp->next;
    }

    temp1->next = temp->next;
    temp->next->prev = temp1;
    delete temp;
    
}
void display(node* &head)
{
    node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL\n";    
}

int main()
{
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtHead(head, 0);
    insert(head, 8, 3);
    deleteAtTail(head);
    deleteHead(head);
    deleteData(head, 8);
    deleteposi(head, 3);
    display(head);

    return 0;
}