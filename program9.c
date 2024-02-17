#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    char name[50];
    struct node *next;
} Node;

Node *head = NULL;

void insertName(char *name);
void deleteName(char *name);
void display();

int main()
{
    int choice;
    char name[50];
    while(1)
    {
        printf("\n 1.Insert a name");
        printf("\n 2.Delete a name");
        printf("\n 3.Display the list");
        printf("\n 4.Exit");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : printf("Enter the name to be inserted \n");
                     scanf("%s",name);
                     insertName(name);
                     break;
            case 2: printf("Enter the name to be deleted\n");
                    scanf("%s",name);
                    deleteName(name);
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("Invalid choice");
        }
    }
}

void insertName(char *name)
{
    Node *newNode=(Node *)malloc(sizeof(Node));
    strcpy(newNode->name,name);
    newNode->next=NULL;
    if(head==NULL || strcmp(head->name,name)>=0)
    {
        newNode->next=head;
        head=newNode;
    }
    else
    {
        Node *current=head;
        while(current->next!=NULL && strcmp(current->next->name,name)<0)
        {
            current=current->next;
        }
        newNode->next=current->next;
        current->next=newNode;
    }
}

void deleteName(char *name)
{
    Node *temp=head,*prev;
    if(temp!=NULL && strcmp(temp->name,name)==0)
    {
        head=temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL && strcmp(temp->name,name)!=0)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("Given name is not found!");
        return;
    }
    prev->next=temp->next;
    free(temp);
}

void display()
{
    Node *ptr=head;
    printf("\nNames in the list:");
    while(ptr!=NULL)
    {
        printf("%s ",ptr->name);
        ptr=ptr->next;
    }
}
