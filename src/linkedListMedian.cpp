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
#include<stdlib.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	if (head == NULL)
	        return -1;

	int array[100];
    int index=0,temp=0,result=0
		;
	while (head != NULL)
	{
		array[index] = head->num;     //moving every node element to an array
		head = head->next;
		++index;
	}

	if (index % 2 == 0){               //if even length then average of 2 mid numbers
		temp = index / 2;
		return (array[temp] + array[temp - 1]) / 2;
	}
	else
		return array[index/2];             //if odd length direct mid value
}
