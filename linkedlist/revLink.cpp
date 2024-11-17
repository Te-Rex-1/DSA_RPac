// %%writefile revLink.cpp
#include<iostream>
using namespace std;
struct Node{
  int data; 
   Node* next;
   Node(int data)
   {
    this->data=data;
    this->next=nullptr;
   }
};


void insAtBack(Node* &head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;  // Initialize head if list is empty
    } else {
        Node* temp = head;
        // Traverse to the end of the list
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;  // Link the new node at the end
    }
}

void print(Node* &head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    } else {
        Node* temp = head;
        // Traverse and print the nodes
        while (temp != nullptr) {
            // Print the node's data
            cout << temp->data;
            // Only print an arrow if it's not the last node
            if (temp->next != nullptr) {
                cout << "->";
            }
            temp = temp->next;
        }
        cout << endl; // Print a new line after the list is printed
    }
}

void rev(Node* &head)
{

    cout<<"starting";
    
  Node* prev=nullptr;
  Node* current=head;
  Node*  forward=nullptr;
  // store next node
  while(current->next!=nullptr){
  forward=current->next;  
  // allocatig pointer to prev node
  current->next=prev;
  prev=current;
  current=forward;
}


}

int main()
{

  Node* node;
  print(node);
  cout<<"Inseart at element"<<endl;
  insAtBack(node,12);
  insAtBack(node,13);
  insAtBack(node,14);
  insAtBack(node,15);
  print(node);

  cout<<node->data;
  cout<<"rev a linked list "<<endl;

  rev(node);
  print(node);
  return 0;
}