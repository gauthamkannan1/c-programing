#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int front = -1, rear = -1;
int queue[MAX_SIZE];

int isEmpty()
{
    return (front == -1 && rear == -1);
}

int isFull()
{
    return ((rear + 1) % MAX_SIZE == front);
}

// Enqueue
void enqueue(int data)
{
    if (isFull())
    {
        printf("Queue is full -- Overflow\n");
        return;
    }

    if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX_SIZE;
    }

    queue[rear] = data;
    printf("%d added to queue\n", data);
}

// Dequeue
void dequeue()
{
    int removed;

    if (isEmpty())
    {
        printf("Queue is empty -- Underflow\n");
        return;
    }

    removed = queue[front];
    printf("%d removed from the queue\n", removed);

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX_SIZE;
    }
}

// Searching
int search(int key)
{
    int i;

    if (isEmpty())
    {
        printf("cannot search, Queue is empty\n");
        return -1;
    }

    i = front;
    do
    {
        if (queue[i] == key)
        {
            printf("Found at position %d\n", i);
            return i;
        }
        i = (i + 1) % MAX_SIZE;
    } while (i != (rear + 1) % MAX_SIZE);

    printf("Not found\n");
    return -1;
}

// Display
void display()
{
    int i;

    if (isEmpty())
    {
        printf("Empty Queue\n");
        return;
    }

    printf("Circular Queue: ");
    i = front;
    do
    {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (rear + 1) % MAX_SIZE);

    printf("\n");
}

// Main
int main()
{
    int choice, data, key;

    while (1)
    {
        printf("\nCircular Queue Operations\n");
        printf("1. Addition\n");
        printf("2. Deletion\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to add: ");
            scanf("%d", &data);
            enqueue(data);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            printf("Enter the element to search: ");
            scanf("%d", &key);
            search(key);
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
