#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node* next;
};

struct Node* createNode(int data)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
// inserattion 
void insertAtBeginning(struct Node** head,int data)

{
    struct Node* newNode=createNode(data);
    newNode->next=*head;
    *head=newNode;
}
void printLinkedList(struct Node* head)
{
    struct Node* temp=head;
    while (temp!=NULL)
    {
        /* code */
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("Null");
    
}

void insertAtLast(struct Node** head,int data)
{
    struct Node* newNode=createNode(data);
    struct Node* temp=*head;
    while(temp->next!=NULL)
    
    {
        temp=temp->next;
    }
    temp->next=newNode;


}
int main() {
    struct Node* head = NULL; // Start with an empty list

    // Insert some nodes
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    insertAtLast(&head,40);
    // Print the list
    printLinkedList(head);


    return 0;
}