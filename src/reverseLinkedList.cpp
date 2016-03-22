/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	if (head == NULL)
		return NULL;           //NULL case condition

	struct node *current_node = head,*prev_node = NULL,*temp;

	while (current_node!= NULL){

		temp = current_node -> next;               //moving next nodes to temp i.e; 2->3->4->5
		current_node -> next = prev_node;          //moving  previous node values to current_node->next
		prev_node = current_node;                 //the current node is moved to prev_node i.e; 1->NULL
		current_node = temp;                      //temp values are moved to current node i.e; 2->3->4->5
	}
	head = prev_node;                            //finally prev_node conatains 5->4->3->2->1->null

	return head;
}
