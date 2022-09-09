#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

#include<iostream>
ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
//*****************************************************
//Adds a new value to the back of the list
//MUST RUN in O(1)
void ULListStr::push_back(const std::string& val){
  //if the list is empty or if the last Item's array is full
  //create a new Item that will be the new tail
  if(tail_==NULL || tail_->last==10){
    Item* temp=new Item; 
    temp->next=NULL; 
    //if the list is empty then the new Item will also be the head
    if(head_==NULL){
      temp->val[5]=val; 
      temp->first=5; 
      temp->last=6;
      temp->prev=NULL;
      head_=temp; 
    }
    else{
      //if the list is not empty then place the string 
      //at the first index(0) of the newly created Item
      temp->val[0]=val;
      temp->first=0;
      temp->last=1;
      temp->prev=tail_; 
      tail_->next=temp; 
    }
      tail_=temp; 
  }
  else{
    //if there is space in the array of the last Item
    //then just place the string in the 'last' index
    tail_->val[tail_->last]=val;
    tail_->last+=1;
  }
  //update size_
  size_ +=1; 
}

void ULListStr::print(){
  Item* ptr=head_; 
  if(ptr==NULL){
    std::cout << "empty list!" << std::endl;
    return; 
  }
  while(ptr!=NULL){
    for(int i=ptr->first;i<int(ptr->last);i++){
      std::cout << ptr->val[i] << std::endl;
    }
    ptr=ptr->next;
  }
}

//Removes a value from the back of the list
//MUST RUN in O(1)
void ULListStr::pop_back(){
  //if the list is empty do nothing and return 
  if(tail_==NULL) return; 
  //if the index of the first item in 'head_' is greater than 0
  if((tail_->last)>0){
    //if there is only one item in the array of 'tail_'
    //and 'tail_' is the only Item in the list, then deallocate 'tail_'
    if((tail_->first)==(tail_->last)-1){
      delete head_; 
      head_=NULL; 
      tail_=NULL; 
    }
    else{
      //if there are more than one item in 'tail_'
      // and 'tail_' is not the only Item in the list 
      tail_->last-=1;
    }
  }
  else{
    //else if the index of the first item in 'head_' is 0
    //if there is only one Item in the array of 'tail_'
    //and 'tail_' is the only Item in the list, then deallocate 'tail_'
    if(tail_->prev==NULL){
      delete head_;
      head_=NULL;
      tail_=NULL;  
    }
    else{
      //if there are more than one item in 'tail_'
      // and 'tail_' is not the only Item in the list move the 'tail_'
      //one Item down
      Item* temp=tail_->prev; 
      temp->next=NULL;
      delete head_; 
      tail_=temp; 
    }
  }
  size_-=1; 
}
  
/*Adds a new value to the front of the list.
If there is room before the 'first' value in
the head node add it there, otherwise, 
allocate a new head node.
MUST RUN in O(1)*/
void ULListStr::push_front(const std::string& val){
  //if the list is empty or the array of the
  //first Item is full create a new Item that will be the new head
  if(head_==NULL || head_->first==0){
    Item* temp=new Item;
    temp->prev=NULL;
    //if the list is empty the new Item will also
    //be the new tail:
    if(tail_==NULL){
      temp->val[5]=val;
      temp->first=5;
      temp->last=6;
      temp->next=NULL;
      tail_=temp;
    }
    else{
      //the 'head_' of the existing list will be replaced
      //by the new Item created 
      temp->val[9]=val;
      temp->first=9;
      //temp->last=-1;
      temp->last=10;
      temp->next=head_;
      head_->prev=temp;
    }
    head_=temp; 

  }
  else{
    //if there is space in the array of the first Item
    //then just place the string at the front of the array
    head_->val[(head_->first)-1]=val;
    head_->first-=1; 
  }
  //increment size_
  size_ +=1; 
}

//Removes a value from the front of the list
//MUST RUN in O(1)
void ULListStr::pop_front(){
  //if the list is empty do nothing and return 
  if(head_==NULL) return; 
  //if the array of 'head_' is not empty
  if(head_->first<9){
    //if there is only one used index in the array and only 
    //one Item in the list then deallocate
    if((head_->first)==(head_->last)-1){
      delete head_;
      head_=NULL;
      tail_=NULL;
    }
    else head_->first +=1;
  }
  else{
    //if there is only item in the array of 'head_'
    //if 'head_' is the only Item in the list, then deallocate
    if(head_->next==NULL){
      delete head_; 
      head_=NULL;
      tail_=NULL;
    }
    else{
      Item* temp=head_->next; 
      temp->prev=NULL;
      delete head_; 
      head_=temp; 
    }
  }
  size_-=1;
}
  
//Returns a const reference to the back element
//MUST RUN in O(1)
std::string const & ULListStr::back() const{
  // if there is nothing in the list just return 
  if(tail_==NULL)return NULL;
  return tail_->val[(tail_->last)-1];
}

// Returns a const reference to the front element
// MUST RUN in O(1)
std::string const & ULListStr::front() const{
  // if there is nothing in the list just return 
  if(head_==NULL)return NULL;
  return head_->val[head_->first];
}

void ULListStr::print_front(){
  std::cout << front() << std::endl;
}

void ULListStr::print_back(){
  std::cout << back() << std::endl;
}
 
/*Returns a pointer to the item at index, loc,
if loc is valid and NULL otherwise
MUST RUN in O(n) */
std::string* ULListStr::getValAtLoc(size_t loc) const{
  //if the index(loc) is greater than the number of elements 
  //in the list or if the number of elements in the list is 0 return NULL
  if(loc>size_ || size_==0 )return NULL;
  //head_size returns the number of elements in the array of 'head_'
  int head_size=(head_->last)-(head_->first);
  //if val[loc] is within the array of 'head_'
  if((int)loc<head_size){
    int place=(int)loc; 
    return &(head_->val[(head_->first)+place]);
  }
  else{
    //if val[loc] if within another Item in the list after 'head_'
    int Item_index=(loc-head_size)/10;
    Item* ptr=head_->next;
    for(int i=0;i<Item_index;i++){
     ptr=ptr->next;
    }
    return &(ptr->val[(loc-head_size)%9]);
  } 
}

//*****************************************************

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}