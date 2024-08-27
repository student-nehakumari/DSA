#include<bits/stdc++.h>
using namespace std;
#include "doubly_linked_list_palindrome.cpp"

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
			newNode->prev = tail;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}



int main()
{
	Node *head = takeinput();
	bool ans = palindromeDLL(head);
	if (ans) cout << "true";
	else cout << "false";

	cout << endl;
	return 0;
}