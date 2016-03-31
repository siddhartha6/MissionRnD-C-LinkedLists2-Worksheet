/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>
struct node {
	int num;
	struct node *next;
};

//insert an element to linked list
struct node *insert(struct node* head, int data)
{
	struct node* new_node = (struct node*) malloc(sizeof(struct node));

	struct node *last = head; 
	new_node->num = data;
	new_node->next = NULL;

	if (head == NULL)
	{
		head = new_node;
		return head;
	}

	while (last->next != NULL)
		last = last->next;

	last->next = new_node;
	return head;
}
struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	
	if (head1 == NULL && head2 == NULL)
	       return NULL;

	struct node *result = NULL;

	while (head1 != NULL && head2 != NULL) {
		if (head1->num < head2->num)          //if list 1 element is less than list2 element
		{
			result = insert(result, head1->num);
			head1 = head1->next;
		}
		else if (head1->num > head2->num)         //if list 2 element is less than list 1 element
		{
			result = insert(result, head2->num);
			head2 = head2->next;
		}
		else                                         //if both the list elements are same then inserting both
		{ 
			result = insert(result, head1->num);  
			result = insert(result, head2->num);
			head1 = head1->next;
			head2 = head2->next;
		}
	}
	while (head1 != NULL)   //if list2 is NULL inserting list1
	{
		result = insert(result, head1->num);
		head1 = head1->next;
	}
	while (head2 != NULL) //if list1 is NULL inserting list2
	{
		result = insert(result, head2->num);
		head2 = head2->next;
	}
	return result;
}
