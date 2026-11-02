#include <iostream>
using namespace std;
class node //the class for every node, it has a pointer already named next
{
    public:
        int data;
        node* next;
};
class linkedlist //class for linkedlist, creates a pointer named head that auto points to null
{
    public:
        node* head= NULL;

    bool isempty() //if head =null it becomes true
{
    return head==NULL;
}
void insertfirst(int value)
{
    if (isempty())
    {
        node* newnode=new node();        //newnode() creates a new node and the part before creates ptr for it
        newnode->data=value;            //assiging the value to the new node through it's pointer
        newnode->next=NULL;            // makes the newnode's pointer point to null since it's now the last node
        head=newnode;
    }
    else 
    {
        node* newnode=new node();       //newnode() creates a new node and the part before creates ptr for it
        newnode->data=value;           //assiging the value to the new node through it's pointer
        newnode->next=head;           //making the node point to the old head because it'll preceed it
        head=newnode;                //making the new node the head
    }
}
void insertpos(int item,int value)
{
    if (head==NULL || head->data==item) //if the list is empty or if item is at start
    {
        node* newnode=new node();
        newnode->data=value;
        newnode->next=head;
        head=newnode;
        return;
    }
    node* temp=head;
    while (temp->next!=NULL && temp->next->data!=item) // find node before item
    {temp=temp->next;}
    if (temp->next==NULL)
    {
        cout<<"item wasn't found";
        return;
    }
    node* newnode=new node();
    newnode->data=value;
    newnode->next=temp->next;
    temp->next=newnode;

}
};
