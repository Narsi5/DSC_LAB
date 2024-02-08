#include<stdio.h>
#include<stdlib.h>

void create();
void display();
void insert(int element,int pos);
void delete(int pos);
int arr[30],n;
void  main(){
	int ch;
	int element,pos;
	printf("1.create\n2.display\n3.insert\n4.delete\5.exit");
	while(1){
		printf("Enter your choice");
		scanf("%d",&ch);
		switch (ch){
		case 1:create();
		       break;
		case 2:display();
		       break;
		case 3:printf("Enter the number to be inserted");
		       scanf("%d",&element);
		       printf("Enter the pos to be inserted");
		       scanf("%d",&pos);
		       insert(element,pos);
		       break;
		case 4:printf("Enter the pos to be del");
		       scanf("%d",&pos);
		       delete(pos);
		       break;
		case 5:
		       exit(0);
		       break;
		default: printf("Invalid choice");
			 break;

		}}

	
}

void create(){
	printf("enter the length of the array");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
	   scanf("%d",&arr[i]);
	}
}
void display(){
	printf("The elements in the array are :");
	for(int i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
	
}
void insert(int element,int pos){
	for(int i=n-1;i>=pos-1;i--){
		arr[i+1]=arr[i];
	}
	arr[pos-1]=element;

	n++;
}
void delete(int pos){
	for(int i=pos;i<=n;i++){
		arr[i-1]=arr[i];
	}
	n--;
}
