#include <stdio.h>
#include <stdlib.h>

typedef struct _ListNode
{
    int val;
    struct _ListNode *next;
} ListNode;

void addNumberToList(ListNode **l, int dato)
{
    ListNode *newNode = malloc(sizeof(ListNode));
    newNode->next = NULL;
    newNode->val = dato;

    if (*l == NULL)
    {
        *l = newNode;
        return;
    }

    ListNode *aux = *l;

    while (aux->next != NULL)
        aux = aux->next;

    aux->next = newNode;
}

void printList(ListNode *l)
{
    ListNode *aux = l;
    while (aux != NULL)
    {
        printf("%d\n", aux->val);
        aux = aux->next;
    }
}

ListNode *swapPairs(ListNode *head)
{
    ListNode *newList = NULL;

    ListNode *aux = head;
    ListNode *l = head;

    int i = 0;

    while (aux != NULL)
    {
        if (l->next == NULL)
        {
            addNumberToList(&newList, l->val);
        }
        else if (l != aux)
        {
            addNumberToList(&newList, aux->val);
            addNumberToList(&newList, l->val);
            l = aux->next;
        }

        aux = aux->next;
    }

    return newList;
}

int main()
{
    ListNode *l1 = NULL;

    addNumberToList(&l1, 1);
    addNumberToList(&l1, 2);
    addNumberToList(&l1, 3);

    printList(swapPairs(l1));
    return 0;
}