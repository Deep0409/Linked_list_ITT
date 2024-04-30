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


void deleteAtBeginning(Node** head) {
  if (*head == NULL) {
    printf("Linked List is empty\n");
    return;
  }

  Node* temp = *head;
  *head = (*head)->next;
  free(temp);
}

void deleteAtEnd(Node** head) {
  if (*head == NULL) {
    printf("Linked List is empty\n");
    return;
  }

  if ((*head)->next == NULL) {
    free(*head);
    *head = NULL;
    return;
  }

  Node* current = *head;
  while (current->next->next != NULL) {
    current = current->next;
  }
  free(current->next);
  current->next = NULL;
}

void deleteAtPosition(Node** head, int index) {
  if (*head == NULL) {
    printf("Linked List is empty\n");
    return;
  }
  
  if (index < 1) {
    printf("Invalid size\n");
    return;
  }
    int count=1;
  Node* temp = *head;
  Node* prev = NULL;

  // Delete head node
  if (index == count) {
    *head = temp->next;
    free(temp);
    return;
  }

  // Search for the node
  while (temp != NULL && count!=index) {
    prev = temp;
    temp = temp->next;
    count++;
  }

  // If not found
  if (temp == NULL) {
    printf("Invalid position\n");
    return;
  }

  // Delete node in the middle or at the end
  prev->next = temp->next;
  free(temp);
}

void print(Node* head) {
  if (head == NULL) {
    printf("Linked List is empty\n");
    return;
  }

  Node* current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

int search(Node* head, int data) {
  int index = 0;
  Node* current = head;
  while (current != NULL) {
    if (current->data == data) 
      return index;
    
    index++;
    current = current->next;
  }
  return -1; // Data not found
}

int size(Node* head) {
  int count = 0;
  Node* current = head;
  while (current != NULL) {
    count++;
    current = current->next;
  }
  return count; // Data not found
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

  //performing the deletion operation
  deleteAtBeginning(&head);
  printf("Linked List after deletion from Beginning : ");
  print(head);
  
  deleteAtEnd(&head);
  printf("Linked List after deletion from End: ");
  print(head);
  
  deleteAtPosition(&head,4);
  printf("Linked List after deletion at position: ");
  print(head);

   // Search operation
  int data = 15;
  int position = search(head, data);
  if (position != -1) {
    printf("%d is found at position %d\n", data, position);
  } else {
    printf("%d is not found\n", data);
  }

//checking data not found case
  data = 15;//position to be deleted
  deleteAtPosition(&head, data);
  printf("Linked List after deletion at position: ");
  print(head);
  
//getting the size of the linked List
 printf("Size of  Linked List : %d\n", size(head));
 
 printf("Final Linked List : ");
 print(head);


    return 0;
}
