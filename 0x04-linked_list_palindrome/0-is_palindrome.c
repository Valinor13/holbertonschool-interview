#include "lists.h"

/**
 * palindrome_recursion - Checks a linked list for bool palindrome
 * @left: &head
 * @right: head
 * Return: returns 0 if false, 1 if true
 */
int palindrome_recursion(listint_t** left, listint_t* right)
{
	int isp = 0, isp1 = 0;

	if (right == NULL)
		return 1;
 
	isp = palindrome_recursion(left, right->next);
	if (isp == 0)
		return 0;
 
	if (right->n == (*left)->n)
		isp1 = 1;
 
	*left = (*left)->next;
 
	return isp1;
}

/**
 * is_palindrome - Checks a linked list for bool palindrome
 * @head: the head pointer of the linked list
 * Return: returns 0 if false, 1 if true
 */
int is_palindrome(listint_t **head)
{
	int result = 1;

	if (!(head) || !(*head->next))
		return (1);
	result = palindrome_recursion(head, *head);
	return (result);
}