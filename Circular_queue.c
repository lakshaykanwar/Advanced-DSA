#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int f = -1, r = -1;

// Enqueue function
void enqueue(int x) {
    // Queue is full
    if ((r + 1) % SIZE == f) {
        printf("Queue is full!\n");
        return;
    }

    // First element
    if (f == -1) {
        f = 0;
        r = 0;
    } else {
        r = (r + 1) % SIZE;
    }

    queue[r] = x;
}

// Dequeue function
void dequeue() {
    int num;

    // Queue is empty
    if (f == -1) {
        printf("Queue is empty!\n");
        return;
    }

    num = queue[f];
    printf("Deleted element: %d\n", num);

    // Only one element was present
    if (f == r) {
        f = -1;
        r = -1;
    } else {
        f = (f + 1) % SIZE;
    }
}

// Display function
void display() {
    int i;

    // Queue is empty
    if (f == -1) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");

    i = f;

    while (1) {
        printf("%d ", queue[i]);

        if (i == r)
            break;

        i = (i + 1) % SIZE;
    }

    printf("\n");
}

// Main function
int main() {
    int choice, x;

    printf("\n1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                enqueue(x);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                printf("f: %d & r: %d\n",f,r);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}