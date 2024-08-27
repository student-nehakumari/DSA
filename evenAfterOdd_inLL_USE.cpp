#include<bits/stdc++.h>
using namespace std;
#include "evenAfterOdd_in_LL.cpp"

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
	node *head = takeinput();
	head = evenAfterOdd(head);
	print(head);
	return 0;
}