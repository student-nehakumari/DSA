#include<bits/stdc++.h>
using namespace std;
#include"merge_sorted_LL.cpp"

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	Node *head1 = takeinput();
	Node *head2 = takeinput();
	Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
	print(head3);
	return 0;
}