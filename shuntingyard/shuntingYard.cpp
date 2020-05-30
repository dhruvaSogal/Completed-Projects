
/*

 Dhruva Sogal Infix/Prefix/Postfix translator. Program turns 4 ops + integers seperated by space and turns into either prefix, postfix, or infix using shunting yard and expression tree

  */

#include <iostream>
#include "node.h"
#include "string.h"
using namespace std;
void enqueu(node* &head, node* current, node* &x, node* &tail); //adds to q
node* dequeu(node* &head, node* current); //removes from q
void push(node* &stackhead, node* current, node* &stacktail, node* x); //adds to stack
node* pop(node* &stackhead, node* &stacktail); //removes from stack FILO
void readInput(node* &head, node* &tail, node* &stackhead, node* &stacktail, int &size); //shuntingyard
void printqueu(node* head, node* tail, node* current);
void stackprint(node* &stackhead, node* &stacktail, node* current);
char* peek(node* stackhead);
void qStack(node* &stackhead, node* &stacktail, node* current, node* &head, node* &tail);
void buildTree(node* &treehead, node* current, node* &shead, node* tail, int &size, node* stacktail); //builds binary expression tree
void infix(node* root); //3 notations
void prefix(node* root);
void postfix(node* root);
int main(){
  int size = 0;
  node* head = NULL;
  node* tail = NULL;
  node* stackhead = NULL;
  node* stacktail = NULL;
  node* treehead = NULL;
  
  
  
  cout<<"Enter your math equation"<<endl;
  readInput(head, tail, stackhead, stacktail, size);
  buildTree(treehead, head, head, tail, size, stacktail);

  cout<<"postfix: "<<endl;
  postfix(treehead);
  cout<<endl;
  cout<<"infix: "<<endl;
  infix(treehead);
  cout<<endl;
  cout<<"prefix: "<<endl;
  prefix(treehead);
  
 
  
   


  
} 

void enqueu(node* &head, node* current, node* &x, node* &tail){ //add things after head FIFO
  
  if(head == NULL){
    
    head = x;
    if(x != NULL){
      //cout<<"qd: "<<x->getToken()<<endl;
    //tail = x;
    }
    
  }
  
  else if(current->getNext() != NULL){

    enqueu(head, current->getNext(), x, tail);

  }
  else{ //end of list
    
    current->setNext(x);
    if(x != NULL){
      //cout<<"qd: "<<x->getToken()<<endl;
    }
  }
  
}




node* dequeu(node* &head, node* current){
  node* k = head;
  head = head->getNext();
  return k;
}


void push(node* &stackhead, node* current, node* &stacktail, node* x){ //FILO, add things before head
  if(stackhead == NULL){
    //node* temp = new node(x);
    stackhead = x;
    //cout<<"pushed: "<<x->getToken()<<endl;
    //stacktail = x;
    
  }
  else{
    node* k = stackhead;
    //node* temp = new node(x);
    stackhead = x;
    stackhead->setNext(k);
    //cout<<"pushed: "<<x->getToken()<<endl;

  }


  
}



node* pop(node* &stackhead, node* &stacktail){
  //stack so last out so
  if(stackhead != NULL){
  node* temp = stackhead;

  if(stackhead->getNext() == NULL){
    stackhead = NULL;
  }
  else{
  stackhead = stackhead->getNext();
  }
  
  //cout<<"popped: "<<temp->getToken()<<endl;
  
 
  return temp;

  }

}


char* peek(node* stackhead){
  char* k = stackhead->getToken();
  //cout<<k<<"fu"<<endl;
  return k;
  
  }



void readInput(node* &head, node* &tail, node* &stackhead, node* &stacktail, int &size){
 
  char* read = new char[90];
  cin.getline(read, 90);
  size = strlen(read);
  read[size] = ' ';   //it only works if I do this and I don't know why
  read[size+1] = '\0';
  size = strlen(read);
  

  for(int i = 0 ; i< size ; i++){
    //cout<<i<< endl;
     char* temp = new char[3];
         if(read[i+1] == ' '){       // if it is independant
	  temp[0] = read[i];
	  temp[1] = '\0';

      }
      
      else if (read[i] != ' ') { //if two digit number
	 temp[0] = read[i];
	 temp[1] = read[i+1];
	 temp[2] = '\0';
	  i++; //as to skip to the next thing

	}


      //what to do if operator
      node* x = new node(temp);
    if((int)read[i] >= 48 && (int)read[i] <= 57){ //if it is a number
      
      
      
      node* x = new node(temp); 
      enqueu(head, head, x, tail);
      
      
      
    }

    else if (read[i] == '*' || read[i] == '/' || read[i] == '+' || read[i] == '-' || read[i] == '^'){ //if it is an operator
      if(stackhead == NULL){
	push(stackhead, stackhead, stacktail, x);
      }
      else{
      
	
	



	//while greater precedence or equal precedence and token is left associative
	
	while(stackhead != NULL && (read[i] == '+' && (*peek(stackhead)) == '*' ||read[i] == '+' && (*peek(stackhead)) == '/' || read[i] == '+' && (*peek(stackhead)) == '^' ||
	      read[i] == '-' && (*peek(stackhead)) == '*' ||read[i] == '-' && (*peek(stackhead)) == '/' || read[i] == '-' && (*peek(stackhead)) == '^' ||
	      read[i] == '*' && (*peek(stackhead)) == '^' ||
	      read[i] == '/' && (*peek(stackhead)) == '^' ||
	      read[i] == '+' && (*peek(stackhead)) == '+' ||  read[i] == '+' && (*peek(stackhead)) == '-' ||
              read[i] == '-' && (*peek(stackhead)) == '+' ||  read[i] == '-' && (*peek(stackhead)) == '-' ||
	      read[i] == '*' && (*peek(stackhead)) == '*' ||  read[i] == '*' && (*peek(stackhead)) == '/' ||
	      read[i] == '/' && (*peek(stackhead)) == '*' ||  read[i] == '/' && (*peek(stackhead)) == '/') 
	      ) 
	{

	


	  
	node* n = pop(stackhead, stacktail);
	pop(stackhead, stacktail);
	enqueu(head, head, n, tail);
	
	
	}
	

      push(stackhead, stackhead, stacktail, x);
      
      }
    }
  //close if operator
  

  else if(read[i] == '('){
  push(stackhead, stackhead, stacktail, x);

    }
   else if(read[i] == ')'){
      while((*peek(stackhead)) != '('){
	node* n = pop(stackhead, stacktail);
	pop(stackhead, stacktail);
	enqueu(head, head, n, tail);
	
      }
      
	pop(stackhead, stacktail);
      

   }
    
    
    
    if(i == (size - 1)){
      //cout<<"sd"<<endl;
      qStack(stackhead, stacktail, stackhead, head, tail);
      //    cout<<"postfix: "<<endl;
    }
    
    
  


  

   
  }
  
}  
   

void printqueu(node* head, node* tail, node* current){ //prints q
  if(current != NULL){
    cout<<current->getToken()<< " ";
    if(current->getNext() != NULL){
      printqueu(head, tail, current->getNext());
      
    }
    else{
      cout<<endl;
    }
    

    } 

}

void stackprint(node* &stackhead, node* &stacktail, node* current){ //prints stack
  if(current != NULL){
    cout<<current->getToken()<<" stack token"<<endl;;
    if(current->getNext() != NULL){
      stackprint(stackhead, stacktail, current->getNext());

    }
    


  }
  


}




void qStack(node* &stackhead, node* &stacktail, node* current, node* &head, node* &tail){ //pops stuff off of the stack onto q
  if(current == NULL){
    cout<<"null"<<endl;
  }
  else{
    node* c = current;
    node* k = pop(stackhead, stacktail);
    pop(stackhead, stacktail); //stackhead?
    
    
    //cout<<"qstack: "<<k->getToken()<<endl;
    
        enqueu(head, head, k, tail);
    
    if(c->getNext() != NULL){
	qStack(stackhead, stacktail, current->getNext(), head, tail);
      }
    
  }

}

void buildTree(node* &treehead, node* current, node* &head, node* tail, int &size, node* stacktail){ //builds tree
  int count = 0;
  char* treestring[90];
  while(true){ //creates an int with value equal to queu elements
    if(current->getNext() != NULL){
      treestring[count] = current->getToken();
      count++;
      current = current->getNext();
    }
    else{
      treestring[count] = current->getToken();
       count++;
       break;
      

     }

   }//end while

  for(int i = 0; i<count; i++){
    //cout<<treestring[i]<<endl;
    if(strcmp(treestring[i], "*") == 0  || strcmp(treestring[i], "/") == 0 || strcmp(treestring[i], "+") == 0 || strcmp(treestring[i], "^") == 0 || strcmp(treestring[i], "-") == 0){
      
      node* n = new node(treestring[i]);
      n->setRight(pop(treehead, stacktail));
      n->setLeft(pop(treehead, stacktail));
      push(treehead, treehead, stacktail, n);
      //cout<<n->getLeft()->getToken()<<endl;
      //cout<<n->getRight()->getToken()<<endl;
      
      
    }
    else{
      node* n = new node(treestring[i]);
      push(treehead, treehead, stacktail, n);





    }


    
  }
  

  

}

void infix(node * root){
  //cout<<"d"<<endl;
  if(root == NULL){
    return;

  }
  // cout<<root->getToken()<<endl;
  infix(root->getLeft());
  cout<<root->getToken()<<" ";
  infix(root->getRight());



}


void prefix(node* root){
  if(root == NULL){
    return;

  }
  
  cout<<root->getToken()<<" ";
  prefix(root->getLeft());
  prefix(root->getRight());


}

void postfix(node* root){
 if(root == NULL){
    return;

  }
 
 postfix(root->getLeft());
 postfix(root->getRight());
 cout<<root->getToken()<<" ";

}


