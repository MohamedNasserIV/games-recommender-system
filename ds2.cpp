#include <iostream>
using namespace std;
class node
{
    public:
     int data;
     node* next;

};
class linkedlist
{
    public:
        node* head=NULL;
bool isempty()
{
    return head==NULL;
}
void display()
{
    node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<","<<endl;
        temp=temp->next;
    }
}
void insertfirst(int value)
{
    if (isempty())
    {
        node* newnode=new node();
        newnode->data=value;
        newnode->next=NULL;
        head=newnode;
    }
    else
    {
        node* newnode=new node();
        newnode->data=value;
        newnode->next=head;
        head=newnode;
    }
}
void insertpos(int value,int item)
{
    if (head==NULL || head->data==item)
    {
        node* newnode=new node();
        newnode->data=value;
        newnode->next=head;
        head=newnode;
        return;
    }
    node* temp=head;
    while (temp->next!=NULL && temp->next->data!=item)
    {temp=temp->next;}
    if (temp->next=NULL)
    {
    cout<<"item was not found in list";
    return;
    }
    node* newnode=new node();
    newnode->data=value;
    newnode->next=temp->next;
    temp->next=newnode;
}
};
int main()
{
    linkedlist L1;
    if (L1.isempty())
        cout<<"The list is empty! ";
    int item;
    cout<<"Enter the value of the first item: "<<endl;
    cin>>item;
    L1.insertfirst(item);
    L1.display();
    
}