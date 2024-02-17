#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}Node;

Node *top = NULL;
void push(int item){
	Node* nn = (Node *)malloc(sizeof(Node));
	nn->data = item;
	nn->next = top;
	top = nn;

}
void pop(){
	if(top == NULL){
		printf("Stack underflow");
		return ;
	}
	else{
		Node *temp = top;
		top = top->next;
		free(temp);
	}
}
void peek(){
	if(top == NULL){
		printf("Stack is empty");
	}
	else{
		printf("%d\n",top->data);
	}
}
void display(){
	Node *temp = top;
	if(temp == NULL){
		printf("Stack is empty");
	}
	else{
		while(temp != NULL){
			printf("%d\n",temp->data);
			temp = temp->next;
		}
	}
}
void main(){
	push(10);
	push(20);
	pop();
	peek();
	display();

	
}
