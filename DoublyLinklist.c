#include <stdio.h>
#include <stdbool.h>

struct node {
   int data;
   int key;
   struct node *next;
   struct node *prev;
};
struct node *head = NULL;
struct node *last = NULL;
struct node *current = NULL;

bool isEmpty() {
   return head == NULL;
}

int length() {
   int length = 0;
   struct node *current;

   for(current = head; current != NULL; current = current->next){
      length++;
   }

   return length;
}
void displayForward() {
   struct node *ptr = head;
   printf("\n[ ");
   while(ptr != NULL) {
      printf("(%d,%d) ",ptr->key,ptr->data);
      ptr = ptr->next;
   }
   printf("]\n");
}


void insertFirst(int key, int data) {
   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->key = key;
   link->data = data;

   if(isEmpty()) {
      last = link;
   } else {
      head->prev = link;
   }
   link->next = head;
   head = link;
}
void insertLast(int key, int data) {
   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->key = key;
   link->data = data;

   if(isEmpty()) {
      last = link;
   } else {
      last->next = link;
      link->prev = last;
   }
   last = link;
}

struct node* deleteFirst() {
   struct node *tempLink = head;
   if(head->next == NULL){
      last = NULL;
   } else {
      head->next->prev = NULL;
   }
   head = head->next;
   return tempLink;
}


struct node* deleteLast() {
   struct node *tempLink = last;
   if(head->next == NULL) {
      head = NULL;
   } else {
      last->prev->next = NULL;
   }
   last = last->prev;
   return tempLink;
}


struct node* delete(int key) {

   struct node* current = head;
   struct node* previous = NULL;
   if(head == NULL) {
      return NULL;
   }

   while(current->key != key) {

      if(current->next == NULL) {
         return NULL;
      } else {
         previous = current;
         current = current->next;
      }
   }
   if(current == head) {
      head = head->next;
   } else {
      current->prev->next = current->next;
   }

   if(current == last) {
      last = current->prev;
   } else {
      current->next->prev = current->prev;
   }

   return current;
}

void main() {
    insertFirst(1,10);
    insertFirst(2,20);
    insertFirst(3,30);
    insertFirst(4,1);
    insertFirst(5,40);
    insertFirst(6,56);

    printf("\n List of Forward : ");
    displayForward();

    printf("\n After deleting first record: ");
    deleteFirst();
    displayForward();

    printf("\n After deleting last record: ");
    deleteLast();
    displayForward();

    printf("\n After delete key(4) : ");
    delete(4);
    displayForward();

    printf("\n After insert last : ");
    insertLast(7,5);
    displayForward();


}
