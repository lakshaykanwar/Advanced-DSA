#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int f = -1, r = -1;

// Enqueue function
void enqueue(int x) {
    if (r == SIZE - 1) {
        printf("Queue is full!\n");
        return;
    } else {
        r = r + 1;
        queue[r] = x;

        if (f == -1) {
            f = 0;
        }
    }
}

// Dequeue function
void dequeue() {
    int num;

    if (f == -1) {
        printf("Queue is empty!\n");
        return;
    } else {
        num = queue[f];
        printf("Deleted element: %d\n", num);
        f = f + 1;
    }

    if (f > r) {
        f = -1;
        r = -1;
    }
}

// Display function
void display() {
    int i;

    if (f == -1) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    for (i = f; i <= r; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, x;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
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
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}