#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    struct node* prev;
    int data;
    struct node* next;
} Node;

Node* getNode() {
    int data;
    printf("Enter the data: ");
    scanf("%d", &data);
    Node* nn = (Node*)malloc(sizeof(Node));
    nn->data = data;
    nn->next = nn->prev = NULL;
    return nn;
}

Node* head = NULL;

void insert(int key) {
    Node *nn = getNode();
    if (head == NULL) {
        head = nn;
    } else {
        Node* temp = head;
        while (temp->next != NULL&& temp->data != key) {
            temp = temp->next;
        }
        if (temp->data == key) {
            nn->next = temp;
            nn->prev = temp->prev;
            if (temp->prev != NULL) {
                temp->prev->next = nn;
            } else {
                head = nn;
            }
            temp->prev = nn;
            return;
        }
	else{
		printf("Key not found");
	}
    }
}

void delete(int key) {
    if (head == NULL) {
        printf("Underflow.\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            if (temp == head) {
                head = temp->next;
                if (head != NULL) {
                    head->prev = NULL;
                }
            } else {
                temp->prev->next = temp->next;
                if (temp->next != NULL) {
                    temp->next->prev = temp->prev;
                }
            }
            free(temp);
            return;
        }
        temp = temp->next;
    }
    printf("Key not found.\n");
}

void display() {
    Node* temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

int main() {
    int choice, num, key;
    while (1) {
        printf("\n1.Insert\n2.Delete\n3.Diplay\n4.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter number to be deleted: ");
                scanf("%d", &num);
                delete(num);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid entry.\n");
        }
    }
    return 0;
}
