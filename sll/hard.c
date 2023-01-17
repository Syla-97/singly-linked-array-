#include <stdio.h>
#define MAX_LENGTH 10
#define SIZE_OVER -3
#define NOT_FOUND -2
#define NO_DATA -1

typedef struct
{
    int data;
    int next;
} Node;

void SLL_init(Node *list)
{
    for (int i = 0; i < MAX_LENGTH; i++)
    {
        list[i].data = 0;
        list[i].next = NO_DATA;
    }

    return;
}

int length(Node *list)
{
    for (int i = 0; i < MAX_LENGTH; i++)
    {
        if (list[i].data == 0)
        {
            return i;
        }
    }
    return SIZE_OVER;
}

int searchData(Node *list, int data, int len)
{
    if (len == SIZE_OVER)
    {
        return SIZE_OVER;
    }
    for (int i = 0, cr = 0; i < len; i++)
    {
        if (list[cr].data == data)
        {
            return i;
        }

        cr = list[cr].next;
    }

    return NOT_FOUND;
}
void push(Node *list, int data)
{
    int len = length(list);
    int res = searchData(list, data, len);

    if (res == SIZE_OVER)
    {
        printf("Size over...\n");
        return;
    }

    if (res >= 0)
    {
        printf("%d is overlapping...\n", data);
        return;
    }

    if (!(len == 0))
    {
        list[len - 1].next = len;
    }

    list[length(list)].data = data;

    printf("%d is pushed to List\n", data);

    return;
}

void removeNode(Node *list, int data)
{
    if (list[0].next == NO_DATA)
    {
        printf("List has not data...\n");
        return;
    }

    int len = length(list);

    int res = searchData(list, data, len);

    if (res == NOT_FOUND)
    {
        printf("%d is not found...\n", data);
        return;
    }

    for (int cr = res; cr < len - 1; cr++)
    {
        list[cr].data = list[list[cr].next].data;
    }

    if (len > 0)
    {
        list[len - 1].data = 0;
        list[len - 2].next = NO_DATA;
    }

    printf("%d is deleted...\n", data);

    return;
}

void removeNodeAll(Node *list)
{
    SLL_init(list);

    return;
}

void printList(Node *list)
{
    if (list[0].next == NO_DATA)
    {
        printf("No data...\n");
        return;
    }

    for (int i = 0;;)
    {
        if (i == NO_DATA)
        {
            break;
        }

        printf("%d ", list[i].data);

        i = list[i].next;
    }

    printf("\n");

    return;
}

int main(void)
{
    Node list[MAX_LENGTH];
    SLL_init(list);

    push(list, 11);
    push(list, 22);
    push(list, 33);
    push(list, 44);
    push(list, 55);

    printList(list);

    removeNode(list, 33);
    removeNode(list, 11);

    push(list, 66);

    removeNode(list, 11);

    push(list, 66);

    removeNodeAll(list);

    printList(list);

    return 0;
}
