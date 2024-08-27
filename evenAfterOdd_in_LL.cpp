#include<bits/stdc++.h>
using namespace std;
#include "node.cpp"
node *evenAfterOdd(node *head)
{
	//write your code here
	if (!head || !head->next) {
    return head;
    }
    
    node *odd = NULL;
    node *even = NULL;
    node *odd_head = NULL;
    node *even_head = NULL;
    
    node *current = head;
    
    while (current!=NULL) {
        if (current->data % 2 != 0) {
            // Odd case
            if (!odd) {
                odd = current;
                odd_head = odd;
            } else {
                odd->next = current;
                odd = odd->next;
            }
        } else {
            // Even case
            if (!even) {
                even = current;
                even_head = even;
            } else {
                even->next = current;
                even = even->next;
            }
        }
        current = current->next;
    }
    if (odd) {
        odd->next = even_head;
    }
    
    if (even) {
        even->next = NULL;
    }
    return odd_head ? odd_head : even_head;
}