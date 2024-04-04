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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *newList = NULL;

    int n1 = 0;

    ListNode *aux = l1;
    ListNode *aux2 = l2;

    int flag = 0;

    while (aux != NULL && aux2 != NULL)
    {
        int l = 0;
        if (flag == 1)
        {
            l = aux->val + aux2->val + 1;
        }
        else
        {
            l = aux->val + aux2->val;
        }
        if (l > 9)
        {
            flag = 1;
            l -= 10;
        }
        else
        {
            flag = 0;
        }

        addNumberToList(&newList, l);

        aux2 = aux2->next;
        aux = aux->next;
    }

    if (aux != NULL)
    {
        while (aux != NULL)
        {
            int l = 0;
            if (flag == 1)
            {
                l = aux->val + 1;
            }
            else
            {
                l = aux->val;
            }

            if (l > 9)
            {
                flag = 1;
                l -= 10;
            }
            else
            {
                flag = 0;
            }

            addNumberToList(&newList, l);
            aux = aux->next;
        }
    }
    else if (aux2 != NULL)
    {
        while (aux2 != NULL)
        {
            int l = 0;

            if (flag == 1)
            {
                l = aux2->val + 1;
            }
            else
            {
                l = aux2->val;
            }

            if (l > 9)
            {
                flag = 1;
                l -= 10;
            }
            else
            {
                flag = 0;
            }

            addNumberToList(&newList, l);
            aux2 = aux2->next;
        }
    }

    if (flag == 1)
    {
        addNumberToList(&newList, 1);
    }

    return newList;
}

int main()
{
    ListNode *l1 = NULL;
    ListNode *l2 = NULL;

    ListNode *l3 = malloc(sizeof(ListNode));

    /* addNumberToList(&l1, 9);
    addNumberToList(&l1, 9);
    addNumberToList(&l1, 9);
    addNumberToList(&l1, 9);
    addNumberToList(&l1, 9);
    addNumberToList(&l1, 9);
    addNumberToList(&l1, 9);

    addNumberToList(&l2, 9);
    addNumberToList(&l2, 9);
    addNumberToList(&l2, 9);
    addNumberToList(&l2, 9); */

    addNumberToList(&l1, 2);
    addNumberToList(&l1, 4);
    addNumberToList(&l1, 3);

    addNumberToList(&l2, 5);
    addNumberToList(&l2, 6);
    addNumberToList(&l2, 4);

    printList(addTwoNumbers(l1, l2));
    return 0;
}