#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //Write your code here
    if(head1==NULL)
    return head2;
    if(head2==NULL)
    return head1;

    Node* mergehead=(head1->data<head2->data)?head1:head2;
    Node* currnode1=mergehead->next;
    Node* currnode2=(mergehead==head1)?head2:head1;

    Node* previous=mergehead;

    //merge two list
    while(currnode1!=NULL && currnode2!=NULL)
    {
      if(currnode1->data < currnode2->data)
      {
        previous->next=currnode1;
        previous=currnode1;
        currnode1=currnode1->next;
      }
      else
      {
        previous->next=currnode2;
        previous=currnode2;
        currnode2=currnode2->next;
      }
    }
    if(currnode1 !=NULL)
    {
      previous->next=currnode1;
    }
    else
    {
      previous->next=currnode2;
    }
    return mergehead;
}