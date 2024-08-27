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
/*to find 1st middle
eg-1,2,3,4 output=2*/
Node* midPoint(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* slow = head;
    Node* fast = head->next;
    //for the second middle 
    // fast=head; in line 21
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;               
    }

    return slow;
}