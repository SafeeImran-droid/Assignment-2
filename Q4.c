#include <stdio.h>

#define MAX 5

void push(int stack[], int *top);
void pop(int stack[], int *top);
void peek(int stack[], int top);
void display(int stack[], int top);

int main() {
    int stack[MAX];
    int top = -1;
    int choice;

    do {
        printf("\nSTACK MENU\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            push(stack, &top);
        else if (choice == 2)
            pop(stack, &top);
        else if (choice == 3)
            peek(stack, top);
        else if (choice == 4)
            display(stack, top);
        else if (choice == 5)
            printf("Exiting...\n");
        else
            printf("Invalid choice.\n");

    } while (choice != 5);

    return 0;
}

void push(int stack[], int *top) {
    if (*top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }

    int val;
    printf("Enter value to push: ");
    scanf("%d", &val);

    (*top)++;
    stack[*top] = val;

    printf("Value pushed\n");
}

void pop(int stack[], int *top) {
    if (*top == -1) {
        printf("Stack Underflow\n");
        return;
    }

    printf("Popped value: %d\n", stack[*top]);
    (*top)--;
}

void peek(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }

    printf("Top value: %d\n", stack[top]);
}

void display(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}
