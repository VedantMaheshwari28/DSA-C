#include <stdio.h>
#define N 5

int queue[N];
int rear = -1, front = -1;

int isEmpty() {
    return rear == -1 || front == -1;
}

int isFull() {
    return rear == N - 1;
}

void peek() {
    if (isEmpty()) {
        printf("Underflow\n");
    } else {
        printf("%d\n", queue[front]);
    }
}

void enqueue(int i) {
    if (isFull()) {
        printf("Overflow\n");
    } else {
        if (rear == -1 && front == -1) {
            rear = front = 0;
        }
    else {
            rear++;
        }
        queue[rear] = i;
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("Underflow\n");
        return -1; // Return -1 to indicate underflow
    } else {
        int item = queue[front];
        front++;
        if (front > rear) {
            front = rear = -1; // Reset the queue
        }
        return item;
    }
}

void display() {
    if (isEmpty()) {
        printf("UNDERFLOW\n");
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%d\n", queue[i]);
        }
    }
}

int main() {
    int choice, m,x;
    while (1) {
        printf("\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Front element\n");
        printf("4. Queue is empty\n");
        printf("5. Queue is full\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");
        scanf("%d", &choice);
        printf("\n");
        if (choice == 7) {
            break;
        }
        switch (choice) {
            case 1:
                printf("ENTER NUMBER TO BE IN QUEUE: ");
                scanf("%d", &m);
                enqueue(m);
                break;
            case 2:
                x=dequeue();
                printf("%d",x);
                break;
            case 3:
                peek();
                break;
            case 4:
                if (isEmpty()) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;
            case 5:
                if (isFull()) {
                    printf("Queue is full\n");
                } else {
                    printf("Queue is not full\n");
                }
                break;
            case 6:
                display();
                break;
            default:
                printf("Enter a valid number\n");
                break;
        }
    }
    return 0;
}