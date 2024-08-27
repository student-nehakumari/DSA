//1.merge sort
//2.reverse LL recursively
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

//1.merge sort

Node* getMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Function to merge two sorted linked lists
Node* merge(Node* left, Node* right) {
    Node* dummy = new Node(0); // Create a dummy node
    Node* temp = dummy;

    while (left != NULL && right != NULL) {
        if (left->data <= right->data) {
            temp->next = left;
            left = left->next;
        } else {
            temp->next = right;
            right = right->next;
        }
        temp = temp->next;
    }
    // Append remaining elements
    temp->next = (left != NULL) ? left : right;

    return dummy->next;
}

//merge sort function
Node *mergeSort(Node *head)
{
	//Write your code here
        if (head == NULL || head->next == NULL)
	    {
            return head;
        }

        // Find the middle node
        Node *mid = getMiddle(head);

        // Divide the list into two halves
        Node *left = head;
        Node *right = mid->next;
        mid->next = NULL; // Temporarily separate the halves
    // Recursively sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    // Merge the sorted halves
    return merge(left, right);
}

//2.reverse LL
Node *reverseLinkedListRec(Node *head)
{
    //Write your code here
	if (head == NULL || head->next == NULL)
  {
    return head;
  }
  Node* newHead = reverseLinkedListRec(head->next);
  Node* temp=newHead;
  while(temp->next!=NULL)
  {
    temp=temp->next;  //last node of resursion reverse function
  }

  temp->next = head;
  head->next = NULL;
  return newHead;
}

// reverse functin method 2 (time complexity -o(n))
class Pair {
	public :
		
			Node *head;
			Node *tail;
};
Pair reverseLL_2(Node *head) {
	if(head == NULL || head -> next == NULL) {
		Pair ans;
		ans.head = head;
		ans.tail = head;
		return ans;
	}

	Pair smallAns = reverseLL_2(head -> next);

	smallAns.tail -> next = head;
	head -> next = NULL;
	Pair ans;
	ans.head = smallAns.head;
	ans.tail = head;
	return ans;
}
//CHANGING RETURN TYPE
Node* reverseLL_better(Node* head)
{
    return reverseLL_2(head).head;
}


//reverse ll method 3(simplest method)

Node *reverseLL_3(Node *head)
{
  if (head == NULL || head->next == NULL)
  {
    return head;
  }
  Node* smallAns = reverseLL_3(head->next);
  Node* tail=head->next;
  tail->next = head;
  head->next = NULL;
  return smallAns;
}

//ITERATIVE METHOD TO REVERSE LL
Node *reverseLinkedList_ITERATIVE(Node *head) {
    // Write your code here
	if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* next;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
		//UPDATE
        prev = curr;
        curr = next;
    }
    return prev;
}
















