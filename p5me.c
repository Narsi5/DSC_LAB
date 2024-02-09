#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 10
int top = -1;
int stack[MAX];

void push(int element) {
    if (top == MAX - 1) // Corrected condition for stack overflow
        printf("Stack overflow\n");
    else
        stack[++top] = element;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1; // Return some default value indicating error
    }
    else
        return stack[top--];
}

void main() {
    char exp[20];
    int num, n1, n2, res;
    int i = 0;
    printf("Enter the postfix expression: ");
    scanf("%s", exp);
    while (exp[i] != '\0') {
        if (isdigit(exp[i])) {
            num = exp[i] - '0';
            push(num);
        } else {
            n2 = pop(); // Corrected order for subtraction and division
            n1 = pop();
            switch (exp[i]) {
                case '+':
                    res = n1 + n2;
                    break;
                case '-':
                    res = n2 - n1;
                    break;
                case '/':
                    res = n2 / n1;
                    break;
                case '*':
                    res = n1 * n2;
                    break;
            }
            push(res);
        }
        i++;
    }
    printf("The result is : %d\n", pop());
}

