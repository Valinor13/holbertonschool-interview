#include "lists.h"

/**
 * palindrome_recursion - Checks a linked list for bool palindrome
 * @left: &head
 * @right: head
 * Return: returns 0 if false, 1 if true
 */
int palindrome_recursion(listint_t** left, listint_t* right)
{
	if (right == NULL)
		return (1);
 
	if (!(palindrome_recursion(left, right->next)))
		return (0);
 
	if (right->n == (*left)->n)
		return (1);
 
	*left = (*left)->next;
 
	return (1);
}

/**
 * is_palindrome - Checks a linked list for bool palindrome
 * @head: the head pointer of the linked list
 * Return: returns 0 if false, 1 if true
 */
int is_palindrome(listint_t **head)
{
	if (!(head) || !(*head))
		return (1);
	return (palindrome_recursion(head, *head));
}
