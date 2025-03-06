#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) 
{
  if (head == NULL) {
    smaller = NULL;
    larger = NULL;
    return;
  }

  // keep track of next node 
  Node* next = head->next;

  //break connection 
  head->next = NULL;

  //process current head node, determine if smaller/larger 

  if (head->val <= pivot) {
    smaller = head;
    llpivot(next, smaller->next, larger, pivot);
  } else {
    larger = head;
    llpivot(next, smaller, larger->next, pivot);
  }
  
}