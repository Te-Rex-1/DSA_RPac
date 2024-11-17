#include<iostream>
using namespace std;
struct Node {

    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr; 
    }
};
Node* insertAtFront(Node* head,int newdata){
    Node* newNode= new Node(newdata);
    newNode->next=head;
    return newNode;
}
main(){
Node* head=new Node(76);

list.insertAtbeg(34);
list.printLIst(list);
return 0;
}