#include<stdio.h>
#include<stdlib.h>

#define MAX 3

int item[MAX];
int front = -1,rear = -1 ;

void insert(int value);
void delete();
void display();

void main(){
	insert(1000);
	insert(1020);
	insert(2000);
	display();
	delete();
	display();

}

void insert(int value){
	if(rear == MAX-1){
		printf("Queue Overflow\n");
	}else{
		if(front == -1)
			front = 0;
		rear +=1;
		item[rear] = value;
		printf("CallerId added -> %d",value);}

	}
void delete(){
	if(front == -1)
		printf("Queue Underflow");
	else{
		printf("CallerId deleted: %d",item[front]);
		front++;
		if(front > rear)
			front = rear = -1;
	}
}

void display(){
	if(rear == -1)
		printf("call queue is empty");
	else{
		printf("\n calls held in the queue are : \n");
		for(int i=0;i<=rear;i++){
			printf("%d",item[i]);
		}
	}
}
