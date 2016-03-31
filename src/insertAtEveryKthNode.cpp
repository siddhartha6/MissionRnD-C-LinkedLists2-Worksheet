/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

void insert_at_pos_K(struct node* ptr, int new_data)
{
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->num = new_data;

	new_node->next = ptr->next;
	ptr->next = new_node;
}

struct node * insertAtEveryKthNode(struct node *head, int K)
{
	if (head == NULL || K <= 0)
		return NULL;

	int count = 0;

	struct node *ptr = head;

	while (ptr->next != NULL){

		count++;
		if (count == K)        //if count is equal to given K value then insert element at K position
		{
			insert_at_pos_K(ptr, K);
			count = -1;
		}
		ptr = ptr->next;
	}
	if (K == 1)      //if K is 1 then inserting 1 at last node
		insert_at_pos_K(ptr, K);
	return head;
}
