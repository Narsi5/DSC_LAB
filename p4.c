//infix to postfix conversion
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 10
int top=-1,stack[MAX];

void push(char elm){
    if(top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top]=elm;
}

char pop(){
    if(top == -1)
        return '\0'; // Return null character to indicate empty stack
    return stack[top--];
}

int priority(char e)
{
    if (e == '(' || e == ')')
        return 0;
    else if (e == '+' || e == '-')
        return 1;
    else if (e == '*' || e == '/')
        return 2;
    return 0;
}

void main(){
    char e[20],x;
    int i=0;
    printf("Enter the infix expression: ");
    scanf("%s",e);
    printf("The postfix expression is: ");

    while(e[i]!='\0'){
        if(e[i] == '('){
            push(e[i]);
        } else if(isalnum(e[i])) {
            printf("%c",e[i]);
        } else if(e[i] == ')') {
            while((x = pop()) != '(' && x != '\0'){ // Stop popping when encountering '(' or an empty stack
                printf("%c",x);
            }
            if (x == '\0') { // If stack is empty before finding '('
                printf("\nInvalid expression: Mismatched parenthesis\n");
                return;
            }
        } else {
            while(top != -1 && priority(stack[top]) >= priority(e[i])){
                printf("%c",pop());
            }
            push(e[i]);
        }
        i++;
    }

    while(top != -1){
        char temp = pop();
        if(temp == '(') {
            printf("\nInvalid expression: Mismatched parenthesis\n");
            return;
        }
        printf("%c",temp);
    }
}

