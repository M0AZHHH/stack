#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;                    // -1 means the stack is empty

int isEmpty(void) {
    return top == -1;
}

int isFull(void) {
    return top == MAX - 1;
}

void push(int x) {
    if (isFull()) {
        printf("Stack is full, cannot push %d\n", x);
        return;
    }
    stack[++top] = x;
    printf("%d pushed\n", x);
}

void pop(void) {
    if (isEmpty()) {
        printf("Stack is empty, nothing to pop\n");
        return;
    }
    printf("Popped: %d\n", stack[top--]);
}

void peek(void) {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top: %d\n", stack[top]);
}

void cleanStack(void) {
    top = -1;
    printf("Stack cleared\n");
}

void printMenu(void) {
    printf("\n1-Push(x)\n2-Pop\n3-Peek\n4-Clean Stack\nChoice: ");
}

void handlePush(void) {
    int x;
    printf("Enter value x: ");
    scanf("%d", &x);
    push(x);
}

void menu(void) {
    int choice;

    while (1) {                  // infinite loop
        printMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input\n");
            while (getchar() != '\n');   // clear bad input
            continue;
        }

        switch (choice) {
            case 1: handlePush();  break;
            case 2: pop();         break;
            case 3: peek();        break;
            case 4: cleanStack();  break;
            default: printf("Invalid choice\n");
        }
    }
}

int main(void) {
    menu();
    return 0;
}