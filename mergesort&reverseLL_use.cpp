#include<bits/stdc++.h>
using namespace std;
#include"mergesort&reverseLL.cpp"
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
	Node *head = takeinput();
    //calling merge sort
	head = mergeSort(head);
	print(head);

    //calling reverse
    head = reverseLinkedListRec(head);                //bruteforce method
	print(head);
	head = reverseLL_better(head);                    //method 2
	print(head);
	head = reverseLL_3(head);                         //method 3
	print(head);
	head = reverseLinkedList_ITERATIVE(head);         //method 4- ITERATIVE METHOD
	print(head);
    return 0;
}