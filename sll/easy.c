#include <stdio.h>
#define MAX_LENGTH 10

typedef struct
{
    int sllList[MAX_LENGTH];
    int length;
} SLL;

void SLL_init(SLL *list)
{
    list->length = 0;

    for (int i = 0; i < MAX_LENGTH; i++)
    {
        list->sllList[i] = 0;
    }
}

int searchData(SLL *list, int data)
{
    if (list->length == 0)
    {
        printf("List has no data...\n");
        return -2;
    }

    for (int i = 0; i < list->length; i++)
    {
        if (list->sllList[i] == data)
        {
            return i;
        }
    }

    return -1;
}

void push(SLL *list, int data)
{
    int res;

    res = searchData(list, data);

    if (list->length == MAX_LENGTH)
    {
        printf("Size over...\n");
        return;
    }

    if (res >= 0)
    {
        printf("%d is overlapping...\n", data);
        return;
    }

    list->sllList[list->length] = data;

    list->length++;

    printf("%d is pushed to List\n", data);

    return;
}

void removeNode(SLL *list, int data)
{
    if (list->length == 0)
    {
        printf("List has not data...\n");
        return;
    }

    int idx = searchData(list, data);

    if (idx < 0)
    {
        printf("%d is not found...\n", data);
        return;
    }

    for (int i = idx; i < list->length; i++)
    {
        list->sllList[i] = list->sllList[i + 1];
    }

    list->sllList[list->length] = 0;

    list->length--;

    return;
}

void removeNodeAll(SLL *list)
{
    SLL_init(list);

    return;
}

void printList(SLL *list)
{
    if (list->length == 0)
    {
        printf("No data...\n");
        return;
    }

    for (int i = 0; i < list->length; i++)
    {
        printf("%d ", list->sllList[i]);
    }

    printf("\n");

    return;
}

int main(void)
{
    SLL sll;
    SLL_init(&sll);

    push(&sll, 11);
    push(&sll, 22);
    push(&sll, 33);
    push(&sll, 44);
    push(&sll, 55);

    printList(&sll);

    removeNode(&sll, 33);
    removeNode(&sll, 11);

    push(&sll, 66);

    removeNode(&sll, 11);

    push(&sll, 66);

    removeNodeAll(&sll);

    printList(&sll);

    return 0;
}
