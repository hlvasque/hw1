/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/
#include "split.h"
#include <cstddef>

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens){
    static Node* even_head = NULL; 
    static Node* odd_head = NULL; 
    static Node* current = in; 
    if(current==NULL){
        if( odds!=NULL)odds->next=NULL;
        if(evens!=NULL)evens->next=NULL; 
        odds=odd_head;
        evens=even_head; 
        return;
    }
    if((current->value)%2==0){
        if(evens==NULL){
            //cout << "in evens' NULL" << endl; 
            evens=current;
            //cout << evens->value << endl;
            current=current->next; 
            even_head=evens; 
        }
        else{
            evens->next=current; 
            evens=evens->next;
            //cout << "evens:" << evens->value << endl;
            current=current->next;
        }
    }
    else if((current->value)%2!=0){
        if(odds==NULL){
            //cout << "in odds' NULL" << endl;
            odds=current;
            //cout << odds->value << endl;
            current=current->next;
            odd_head=odds; 
        }
        else{
            odds->next=current;
            odds=odds->next;
            //cout << "odds:" << odds->value << endl;
            current=current->next;
        }
    }
    return split(current, odds, evens);
}
