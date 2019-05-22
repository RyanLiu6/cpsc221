// linked_list.cc -- functions for linked_list lab (cs221) 

#include "linked_list.h"
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

/**
 * Inserts a new Node (with key=newKey) at the head of the linked_list.
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 * PRE: newKey is the value for the key in the new Node 
 * POST: the new Node is now the head of the linked_list
 */ 
void insert(Node*& head, int newKey) {
  Node * curr = new Node;
  curr->key  = newKey;
  curr->next = head;

  head = curr;
}

/**
 * Print the keys of a linked_list in order, from head to tail 
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 */ 
void print(Node* head) {
  std::cout << "[";
  for (Node* curr = head; curr != NULL; curr = curr->next){ 
    std::cout << curr->key;
    if (curr->next != NULL) std::cout << ", ";
  }
  std::cout << "]" << std::endl;
}

/** 
 * Returns the size (number of Nodes) of the linked_list  
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 */ 
int size(Node* head){ 
  if (! head) return 0; 
  return 1 + size(head->next); 
}

/**
 * Copies the keys in a linked list to a vector.
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 * POST: a new vector<int> containing the keys in the correct order has been returned.  
 */ 
std::vector<int> to_vector(Node* head) {
  std::vector<int> result;
  for (Node* curr = head; curr != NULL; curr = curr->next){ 
    result.push_back(curr->key); 
  }
  return result; 
}

/** 
 * Delete the last Node in the linked_list
 * PRE: head is the first Node in a linked_list (if NULL, linked_list is empty) 
 * POST: the last Node of the linked_list has been removed
 * POST: if the linked_list is now empty, head has been changed
 * POST: else head remains the first Node in the linked_list
 */
void delete_last_element(Node*& head){
  // ******** WRITE YOUR CODE HERE ********
  if (head != NULL) {
    Node* curr = head;
    Node* prev;

    if (curr->next != NULL) {
      while(curr->next != NULL) {
        prev = curr;
        curr = curr->next;
      }
      prev->next = NULL;
      delete curr;
    }

    else {
      delete head;
      head = NULL;
    }
  }
}

/**
 * Removes an existing Node (with key=oldKey) from the linked_list. 
 * PRE: head is the first node in a linked_list (if NULL, linked_list is empty) 
 * PRE: oldKey is the value of the key in the Node to be removed 
 * PRE: if no Node with key=oldKey exists, the linked_list has not changed 
 * POST: if a Node with key=oldKey was found, then it was deleted
 * POST: other Nodes with key=oldKey might still be in the linked_list
 * POST: head is the new first Node of the linked_list, if updated
 */ 
void remove(Node*& head, int oldKey) {
  // ******** WRITE YOUR CODE HERE ********
  if (head != NULL) {
    int pos;
    Node* prev;
    Node* forward;
    Node* curr;
    std::vector<int>::iterator iter;
    std::vector<int> key = to_vector(head);

    iter = std::find(key.begin(), key.end(), oldKey);
    if(iter != key.end()) {
      pos = std::distance(key.begin(), iter);

      curr = head;
      if (curr->next != NULL) {
        for (int i = 0; i < (pos); i++) {
          prev = curr;
          curr = curr->next;
        }

        if (curr->next != NULL) {
          forward = curr->next;
          prev->next = curr->next;
        }

        else {
          forward = NULL;
        }

        delete curr;
        prev->next = forward;
      }

      else {
        delete head;
        head = NULL;
      }
    }
  }
}

/**
 * Insert a new Node (with key=newKey) after an existing Node (with key=oldKey)
 * If there is no existing Node with key=oldKey, then no action.
 * PRE: head is the first Node in a linked_list (if NULL, linked_list is empty) 
 * PRE: oldKey is the value to look for (in the key of an existing Node)  
 * PRE: newKey is the value of the key in the new Node (that might be inserted) 
 * POST: if no Node with key=oldKey was found, then the linked_list has not changed
 * POST: else a new Node (with key=newKey) is right after the Node with key = oldKey.
 */
void insert_after(Node* head, int oldKey, int newKey){
  // ******** WRITE YOUR CODE HERE ********
  if (head != NULL) {
    int pos;
    Node* forward;
    Node* curr;
    std::vector<int>::iterator iter;
    std::vector<int> key = to_vector(head);

    iter = std::find(key.begin(), key.end(), oldKey);
    if(iter != key.end()) {
      pos = std::distance(key.begin(), iter) + 1;
      //std::cout << "Position is: " << pos << std::endl;

      curr = head;
      for (int i = 0; i < (pos-1); i++) {
        curr = curr->next;
      }

      Node* ins = new Node;
      ins->key = newKey;

      if (curr->next != NULL) {
        forward = curr->next;
        curr->next = ins;
        ins->next = forward;
      }

      else {
        curr->next = ins;
        ins->next = NULL;
      }
    }
  }
}

/** 
 * Create a new linked_list by merging two existing linked_lists. 
 * PRE: list1 is the first Node in a linked_list (if NULL, then it is empty)
 * PRE: list2 is the first Node in another linked_list (if NULL, then it is empty)
 * POST: A new linked_list is returned that contains new Nodes with the keys from 
 * the Nodes in list1 and list2, starting with the key of the first Node of list1, 
 * then the key of the first Node of list2, etc. 
 * When one list is exhausted, the remaining keys come from the other list.
 * For example: [1, 2] and [3, 4, 5] would return [1, 3, 2, 4, 5]
 */
Node* interleave(Node* list1, Node* list2){
  // ******** WRITE YOUR CODE HERE ********
  Node* start = new Node;
  Node* start_2 = NULL;
  if (list1 != NULL || list2 != NULL) {
    int n = size(list1);
    //std::cout << n << std::endl;
    int m = size(list2);
    //std::cout << m << std::endl;

    std::vector<int> key1 = to_vector(list1);
    std::vector<int> key2 = to_vector(list2);

    std::vector<int> result;

    int l = std::min(n,m);

    for (int i = 0; i < l; i++) {
      result.push_back(key1.at(i));
      result.push_back(key2.at(i));
    }

    if (l < n) {
      result.insert(result.end(), key1.begin()+l, key1.end());
    }

    if (l < m) {
      result.insert(result.end(), key2.begin()+l, key2.end());
    }

    // Looking if result has the correct numbers pushed in
    for (int k = 0; (unsigned) k < result.size(); k++){
      std::cout << result[k] << " ";
    }
    std::cout << std::endl;

    /*insert(start, result.at(0));
    for (int j = 1; j < (n+m); j++) {
      // std::cout << result.at(j-1) << " ";
      //std::cout << "Current Number is: " << result.at(j) << " || ";
      // std::cout << "Loop +" << std::endl;
      //insert_after(start, result.at(j-1), result.at(j));
      //start->key = res;
      //start = start -> next;
    }*/

    start_2 = start;
    for (int j = 0; j <(n+m); j++) {
       	start->key = result.at(j);

       	if (j < (n+m - 1)){
   			start = start->next = new Node;
    	}
    }
  }
  return start_2;
}
