#include<stdio.h>
#include<stdlib.h>

#define MAX 5

struct CircularQueue{
	int data;
};

struct CircularQueue queue[MAX];
int front = -1,rear=-1;

void insert(int value);
void delete();
void display();

void main()
{
	insert(1);
	display();
	insert(2);
	display();
	insert(3);
        display();
	insert(4);
        display();
	insert(5);
        display();
	delete();
	display();



}

void insert(int value){
	if((front == 0&& rear==  MAX -1) || (rear + 1 == front)){
		printf("Ciruclar Queue is full\n");
		return;
	}
	if(front == -1){
		front = rear = 0;
	}
	else{
		rear = (rear+1)%MAX;
	}
	queue[rear].data = value;
}
void delete(){
	int value;
		if(front == -1){
			printf("queue overflow");
		}
		value = queue[front].data;
		if(front == rear){
			front = rear = -1;
		}
		else{
			front = (front +1)%MAX;

		}
		printf("\ndeleted element %d\n",value);

}

void display(){
	if(front == -1)
		printf("Empty queue");
	else{
		
		printf("\n");
		for(int i = front ;i!=rear ;i=(i+1)%MAX){
			printf("%d -->\t ",queue[i].data);
		}
		printf("\n");
		
	}
}

