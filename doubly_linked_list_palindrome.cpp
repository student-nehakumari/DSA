#include<bits/stdc++.h>
using namespace std;
class Node
        {
        public:
	        int data;
	        Node *next;
			Node *prev;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
				this->prev = NULL;
	        }
        };
bool palindromeDLL(Node* head){
    if (head == NULL || head->next == NULL) {
        return true; // Empty or single-node list is a palindrome
    }

    Node* slow = head;
    Node* fast = head;

    // Find the middle node using fast and slow pointers (Floyd's Cycle Finding Algorithm)
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // If fast has one node left (odd number of nodes), advance slow one more
    if (fast != NULL) {
        slow = slow->next;
    }

    // Reverse the second half of the list (in-place reversal)
    Node* prev = NULL;
    Node* curr = slow;
    while (curr != NULL) {
        Node* next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }

    // Compare nodes from head and the reversed second half
    Node* left = head;
    Node* right = prev;
    while (left != NULL && right != NULL) {
        if (left->data != right->data) {
            return false;
        }
        left = left->next;
        right = right->next;
    }
    return true;
}