/* Write your test code for the ULListStr in this file */
#include "ulliststr.h"
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
ULListStr dat;
  dat.push_front("3");
  dat.push_front("2");
  dat.push_front("1");
  dat.push_back("4");
  dat.push_back("5");
  dat.push_back("6");
  dat.push_back("7");
  dat.push_back("8");
  dat.push_back("9");
  dat.push_back("10");
  dat.push_front("0");
  dat.push_front("-1");
  dat.push_front("-2");
  dat.push_front("-3");
  dat.push_front("-4");
  cout << "Added 15 items:" << endl;
  dat.print();
  cout << endl; 
  cout << "popping 14 of the 15 items" << endl;
  for(int i=0; i< 14; i ++){
    dat.pop_front();
  }
  cout << "popping the last of the 15 items" << endl;
  dat.print();
  cout << endl;
  //pop the last item 
  dat.pop_back();
  dat.print();
  //tests pop_front() w/ an empty list
  dat.pop_front();
  //tests pop_back() w/ an empty list
  dat.pop_back();
  
  //tests push_back() with a reused list
  cout << "Added 5 items:" << endl;
  dat.push_back("1");
  dat.push_back("2");
  dat.push_back("3");
  dat.push_back("4");
  dat.push_back("5");
  dat.print();
  cout << endl;
  cout << "popping the 5 items added" << endl;
  for(int i=0;i<5;i++){
    dat.pop_back(); 
  }
  cout << "Added two items:" << endl;
  dat.push_front("9");
  dat.push_front("8");
  dat.print_front();
  dat.print_back();
  cout << "popping those two items" << endl;
  cout << endl;
  dat.pop_back();
  dat.pop_back();

  cout << "Added 11 items:" << endl;
  for(int i=0;i<11;i++)dat.push_back("8");
  for(int i=0;i<11;i++){
    cout << dat.get(i) << endl;
  }
  cout << endl;
  cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(10) << endl;
  cout << endl;
  cout << "testing dat.get() at a bad index" << endl;
  cout << dat.get(11) << endl;
  ULListStr Test;
  cout << "testing dat.get() on an empty list" << endl;
  cout << Test.get(0) << endl;
  return 0;
}
