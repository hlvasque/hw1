#include "split.h"
#include <iostream>
using namespace std; 

int main(){
    Node Node4(7,NULL);
    Node Node3(6,&Node4);
    Node Node2(5,&Node3);
    Node Node1(4,&Node2);
    
    Node* in_ptr=&Node1; 
    Node* even=NULL;
    Node* odd=NULL;
    
    split( in_ptr, odd, even);
    
    Node* temp=odd; 
    cout << "components in odd list:" << endl;
    while(temp != NULL){
        cout << temp->value << endl;
        temp=temp->next; 
    }
    cout << endl;
    cout << "componets in even list:" << endl; 
    temp=even; 
    while(temp != NULL){
        cout << temp->value << endl;
        temp=temp->next; 
    }
    
    
}