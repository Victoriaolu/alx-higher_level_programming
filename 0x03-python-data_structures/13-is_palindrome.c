#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if the singly linked list is a palindrome.
 * Return:0 if not palindrome,1 if palindrome.
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow = *head, *fast = *head, *prev_slow = *head, *midnode = NULL;
    listint_t *second_half, *prev_of_slow = *head;
    int res = 1; // 1 means true, 0 means false

    if (*head != NULL && (*head)->next != NULL) {
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            prev_slow = slow;
            slow = slow->next;
        }

        if (fast != NULL) {
            midnode = slow;
            slow = slow->next;
        }

        second_half = slow;
        prev_slow->next = NULL;
        reverse(&second_half);
        res = compare(*head, second_half);
        reverse(&second_half);

        if (midnode != NULL) {
            prev_slow->next = midnode;
            midnode->next = second_half;
        } else {
            prev_slow->next = second_half;
        }
    }

    return res;
}



 
