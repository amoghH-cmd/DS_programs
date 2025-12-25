#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int q[MAX];
int front = -1, rear = -1;

void insert();
void del();
void display();

int main()
{
    int ch;

    for (;;)
    {
        printf("\nIMPLEMENTATION OF QUEUE USING ARRAY");
        printf("\n1 : INSERT");
        printf("\n2 : DELETE");
        printf("\n3 : DISPLAY");
        printf("\n4 : EXIT");
        printf("\nEnter your Choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            del();
            break;
        case 3:
            display();
            break;
        default:
            exit(0);
        }
    }
}

void insert()
{
    int item;

    if (rear == MAX - 1)
    {
        printf("\nQUEUE OVERFLOW\n");
        return;
    }

    if (front == -1)
        front = 0;

    printf("\nEnter the element : ");
    scanf("%d", &item);

    q[++rear] = item;
}

void del()
{
    int item;

    if (front == -1 || front > rear)
    {
        printf("\nQUEUE UNDERFLOW\n");
        return;
    }

    item = q[front++];
    printf("\nDeleted element is %d\n", item);

    if (front > rear)
        front = rear = -1;
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("\nQUEUE IS EMPTY\n");
        return;
    }

    printf("\nElements in the Queue are:\n");
    for (i = front; i <= rear; i++)
        printf("%d ", q[i]);
    printf("\n");
}
