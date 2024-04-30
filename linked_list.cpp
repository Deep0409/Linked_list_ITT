#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

Node* createNode(int data) {
  Node* new_Node = (Node*)malloc(sizeof(Node));
  new_Node->data = data;
  new_Node->next = NULL;
  return new_Node;
}

void insertAtBeginning(Node** head, int data) {
  Node* new_Node = createNode(data);
  new_Node->next = *head;
  *head = new_Node;
}

void insertAtEnd(Node** head, int data) {
  Node* new_Node = createNode(data);
  if (*head == NULL) {
    *head = new_Node;
    return;
  }

  Node* last = *head;
  while (last->next != NULL) {
    last = last->next;
  }
  last->next = new_Node;
}

void insertAtPosition(Node** head, int data, int position) {
  if (position < 1) {
    printf("Invalid position\n");
    return;
  }

  if (position == 1) {
    insertAtBeginning(head, data);
    return;
  }

  Node* newNode = createNode(data);
  Node* current = *head;
  int count = 1;

  while (current != NULL && count < position - 1) {
    current = current->next;
    count++;
  }

  if (current == NULL) {
    printf("Invalid position\n");
    return;
  }

  newNode->next = current->next;
  current->next = newNode;
}






int main()
{
    Node* head = NULL;

 
  insertAtEnd(&head, 10);
  insertAtEnd(&head, 20);
  insertAtEnd(&head, 30);
  insertAtEnd(&head, 40);
  insertAtEnd(&head, 50);
  insertAtEnd(&head, 60);
  insertAtEnd(&head, 70);
  insertAtEnd(&head, 80);
  insertAtEnd(&head, 90);
  insertAtEnd(&head, 100);
  insertAtBeginning(&head, 5);
  insertAtPosition(&head, 15, 3);
  
  
  printf("Linked List: ");
  print(head);

  

    return 0;
}
