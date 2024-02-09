#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5

int top=-1,stack[MAX_SIZE];

void push(int elm){
	if(stack[top]==MAX_SIZE){
		printf("stack overflow");}
	stack[++top]=elm;

}

int pop(){
	if(stack[top]==-1)
		printf("stack underflow");
	return stack[--top];
}

void display(){

	for(int i=0;i<=top;i++){
		printf("%d th element is %d\n",i,stack[i]);
	}

}

void palindrome(){
    int floor = 0, max = top, flag = 0;
    while (floor <= top / 2)
    {
        if (stack[floor] != stack[max])
        {
            flag = 1;
            break;
        }
        max--;
        floor++;
    }

    if (flag == 1)
    {
        printf("It is not a palindrome\n");
    }
    else
    {
        printf("It is a palindrome\n");
    }
}

int main(){

    int ch,elm;
    while (1)
    {
        printf("1.PUSH\n2.POP\n3.PALINDROME\n4.DISPLAY\n5.PEEK\n6.EXIT\nENTER CHOICE:");
        scanf("%d", &ch);
        switch (ch)
        {
		case 1:printf("Enter the element to be pushed:");
		       scanf("%d",&elm);
            push(elm);
            break;
        case 2:
            pop();
            break;
        case 3:
            palindrome();
            break;
        case 4:
            display();
            break;
        

        default:
            exit(0);
        }
	display();


    }}
