#include<bits/stdc++.h>
using namespace std;
#include "node.cpp"

node *swapnodes(node *head, int i, int j)
{
	//Write your code here
	if (i < 0 || j < 0 || i == j) {
    return head;
  }

  // Two pointers to traverse the list
  node* prev_i = nullptr;
  node* curr_i = head;
  node* prev_j = nullptr;
  node* curr_j = head;

  // Find the i-th and j-th nodes
  int count = 0;
  while (curr_i != nullptr && count < i) {
    prev_i = curr_i;
    curr_i = curr_i->next;
    count++;
  }

  count = 0;
  while (curr_j != nullptr && count < j) {
    prev_j = curr_j;
    curr_j = curr_j->next;
    count++;
  }

  // nodes not found (positions out of range)
  if (curr_i == nullptr || curr_j == nullptr) {
    return head;
  }

  // Swap pointers (handle different cases)
  if (prev_i == nullptr) { // i-th node is the head
    head = curr_j;
  } else {
    prev_i->next = curr_j;
  }

  if (prev_j == nullptr) { // j-th node is the head
    head = curr_i;
  } else {
    prev_j->next = curr_i;
  }

  // Swap the next pointers of the swapped nodes
  node* temp = curr_i->next;
  curr_i->next = curr_j->next;
  curr_j->next = temp;

  return head;
}

//driver code

node *takeinput()
{
	int data;
	cin >> data;
	node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		node *newnode = new node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(node *head)
{
	node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int i, j;
		node *head = takeinput();
		cin >> i;
		cin >> j;
		head = swapnodes(head, i, j);
		print(head);
	}
	return 0;
}