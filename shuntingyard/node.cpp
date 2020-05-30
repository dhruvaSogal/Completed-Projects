//Node class with next, left, and right. This class is suitable for both singly linked lists and trees
#include<iostream>
#include "node.h"
node::node(char* k){ //makes node with char* value
  token = k;

}
node::~node(){ //destructor
  delete next;
  delete right;
  delete left;
  delete token;


}
char* node :: getToken(){ //returns token
  return token;

}
void node :: setToken(char* k){ //sets token if change needed
  token = k;

}
node* node :: getLeft(){ //gets left
  return left;
}
node* node :: getRight(){ //gets right
  return right;

}
node* node :: getNext(){ //getes next
  return next;

}
void node :: setLeft(node* k){ //sets left right next
  left = k;

}
void node :: setRight(node* k){
  right = k;

}
void node :: setNext(node* k){
  next = k;

}
