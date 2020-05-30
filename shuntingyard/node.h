//node class with left and right pointers as well as next. usable in both list and tree
#include<iostream>
using namespace std;
class node{
public: //functions
  node(char* k); 
  ~node();
  node* getLeft();
  node* getRight();
  node* getnext();
  void setLeft(node* k);
  void setNext(node* k);
  node* getNext();
  void setRight(node*k);
  char getValue();
  char* getToken();
  void setToken(char* k);
private: //values
  node* left;
  node* right;
  node* next;
  char* token;
  








};
