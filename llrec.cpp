#include "llrec.h"
#include <iostream> //testing 
//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) 
{
  
  //base 
  if (head == NULL) {
    smaller = NULL;
    larger = NULL; 
    return;
  }
  Node* curr = head;
  head = head->next;
  if (curr->val <= pivot) {
    smaller = curr;
    llpivot(head, smaller->next, larger, pivot);
   
  } else {
    larger = curr;
    llpivot(head, smaller, larger->next, pivot);
    
  }
  
}