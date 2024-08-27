#include<bits/stdc++.h>
using namespace std;
#include "midpoint_LL.cpp"

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
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

int main()
{
	Node *head = takeinput();
	Node *mid = midPoint(head);
	if (mid != NULL)
	{
		cout << mid->data;
	}
	cout << endl;
	return 0;
}