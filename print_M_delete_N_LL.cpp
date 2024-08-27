#include<bits/stdc++.h>
using namespace std;
#include "node.cpp"

node *skipMdeleteN(node *head, int M, int N)
{
	// Write your code here
	if (head == NULL || M <= 0 || N < 0) {
        return NULL;  // Edge case: invalid input or nothing to process
    }
    
    node *current = head;
    node *prev = NULL;
    
    while (current!=NULL) {
        // Skip M nodes
        int countM = 0;
        while (current && countM < M) {
            prev = current;
            current = current->next;
            countM++;
        }
        
        // Delete N nodes
        int countN = 0;
        while (current!=NULL && countN < N) {
            node *temp = current;
            current = current->next;
            delete temp;
            countN++;
        }
        
        // Connect the previous part to the remaining list
        if (prev!=NULL) {
            prev->next = current;
        } else {
            head = current;  // Update head if all nodes are deleted
        }
    }
    
    return head;
}


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
	int m, n;
	cin >> m >> n;
	head = skipMdeleteN(head, m, n);
	print(head);
	return 0;
}