/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	if (head == NULL)
	        return -1;
	int a[100],i=0,temp=0,result=0;
	while (head != NULL)
	{
		a[i] = head->num;
		head = head->next;
		++i;
	}

	if ((i + 1) % 2 == 0){
		temp = i / 2;
		result = (a[temp] + a[temp + 1]) / 2;
	}
	else
		result = a[i/2];
	return result;
}
