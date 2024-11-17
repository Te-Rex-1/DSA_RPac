#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;


};

struct Queue{
    struct Node* front,*rear;
};

// here it is used to create new node for easy intilzation 
struct Node* createNode(int value){
      struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
      temp->data=value;
      temp->next=NULL;
      return temp;
}
int  enQueue(struct Queue* q,int data)
{
      struct Node* temp = createNode(data);
      // if queue is nulll
      if(q->front==NULL)
      {

            q->front=q->rear=temp;
            q->rear->next=q->front;
                return 1;

        
      }
      else{
        // link new node to last 
        q->rear->next=temp;
         q->rear=temp;
      q->rear->next=q->front;
      return 1;

      }

      return 0;
     


}
int  deQueue(struct Queue* q)
{
    if(q->front==NULL)
    {
        printf("Queue is empty \n");
        return 0;
    }
    int removed;
    // only 1 element is present 
    if(q->front==q->rear)
    {
        removed=q->front->data;
        free(q->front);
        q->front=q->rear=NULL;
   

    }
    // more then 1 elem is present
       removed = q->front->data;
        struct Node* temp = q->front;
        q->front = q->front->next;
        q->rear->next = q->front;  // Update rear's next pointer in a circular queue
        free(temp);

    return removed;
    
}void displayQueue(struct Queue* q) {
    // Check if the queue is empty
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = q->front;
    printf("Queue elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q->front);  // Loop until we circle back to the front
    printf("\n");
}
int main ()
{

        struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
        
        q->front=q->rear=NULL;

        printf("%d\n", enQueue(q, 14));
         printf("%d\n", enQueue(q, 15));

        displayQueue(q);
                  printf("%d\n", deQueue(q));

                  displayQueue(q);


    return 0;
}