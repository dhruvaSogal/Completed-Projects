
#include <iostream>
#include <fstream>
#include <assert.h>
using namespace std;
struct node{
  int value;
  node* right;
  node* left;
  node* parent;
  char color;

};
void rotateRight(node* k);
void read(node* &root);
void fix(node* &root, node* k);
void step2(node* k);
node* getSibiling(node* root, node* k);
node* getUncle(node* root, node* k);
node* getGrandparent(node* k);
void rotateRight(node* k);
void rotateLeft(node* k);
void insert(node* a , node* current, node* &root);
void insertFix(node* k, node* &root);
void print(node* current, int space);
void add(int x, node* &root);
void ReplaceNode(node*k, node* child);
void deleteChild(node* root, node* k);
void deleteCase1(node* root, node* k);
void deleteCase2(node* root, node* k);
void deleteCase3(node* root, node* k);
void deleteCase4(node* root, node* k);
void deleteCase5(node* root, node* k);
void deleteCase6(node* root, node*k);
void search(int key, node* current);
void deleteNode(int key, node* current, node* root);
node* findInorderSuccesor(node* c);
void deleteInorderSuccesor(node* &c);
void deleteLeaf(int key, node* &current, node* &root);
int main(){
  node* root = NULL;
  //root->color = 'b';
  cout<<"Enter 'p' for print, 'r' for read, 's' to search, 'd' to delete or q to quit"<<endl;
  char com;
  while(true){
  cin>>com;


  //if(com == 'a'){
  //cout<<"Enter the number you wish to add"<<endl;
  //int z;
  //cin>>z;
  //add(z, root);

  //}
  if(com == 'p'){
    print(root, 0);

  }
  if(com == 'r'){
    read(root);
    cout<<root->value<<endl;
  }
  if(com == 'd'){
    cout<<"enter the number you wish to delete"<<endl;
    int n;
    cin>>n;
    deleteNode(n, root, root);
  }
  if(com == 's'){
    cout<<"enter the number you wish to find"<<endl;
    int n;
    cin>>n;
    search(n, root);
  }
  if(com == 'q'){
    break;

  }

  
  
  
  }




}
void read(node* &root){ //reads input and calls insert method
  cout<<"Enter 1 for console entry or 2 for file input"<<endl;
  int entry = 0;
  //cin.ignore();
  cin>>entry;
  if(entry == 1){
    char* input = new char[100];
    cout<<"Enter up to 100 numbers seperated by spaces"<<endl;
    cin.ignore();
    cin.get(input, 100);
    ofstream file;
    file.open("treefile");
    file<<input;
    file.close();
    ifstream infile;
    infile.open("treefile");
    int a;
    while(infile >> a){
      //cout<<a<<endl;
      node* k = new node;
      k->value = a;
      k->left = NULL;
      k->right = NULL;
      k->parent = NULL;
      insertFix(k, root);
    }

  }

  if(entry == 2){
    cout<<"Enter file name"<<endl;
    char* filename = new char[100];
    cin.ignore();
    cin.get(filename, 100);
    ifstream infile;
    infile.open(filename);
    if(infile.fail()){
      cout<<"no such file exists"<<endl;
    }
    
    else{
      int a;
      while(infile >> a){
      node* k = new node;
      k->value = a;
      k->left = NULL;
      k->right = NULL;
      k->parent = NULL;

      insertFix(k, root);
      }
    }
  }
}//end read method

void insert(node* a , node* current, node* &root){ //inserts elements appropriately into tree
  if(root == NULL){
    root = a;
  }
  else{ //root not equal to NULL
    if(a->value < current->value){
      if(current->left != NULL){
	insert(a, current->left, root);

      }
      else{
	current->left = a;
	a->parent = current;
	a->left = NULL;
	a->right = NULL;

      }
    }

      else if(a->value > current->value || a->value == current->value){
	if(current->right != NULL){
	insert(a, current->right, root);

      }
      else{
	current->right = a;
	a->parent = current;
	a->left = NULL;
	a->right = NULL;

      }
	

      }


    }
    

  a->color = 'r';

  }


void fix(node* &root, node* k){
  
  if(k->parent == NULL){
    k->color = 'b';
        
  }
  else if(k->parent->color == 'b'){
    return;
    
  }
  else if(getUncle(root, k)!= NULL && getUncle(root, k)->color == 'r'){
    //case 3 wikipedia
    k->parent->color = 'b';
    getUncle(root, k)->color = 'b';
    getGrandparent(k)->color = 'r';
    fix(root, getGrandparent(k));
    
  }
  else{
      
    node* p = k->parent;
    node* g = getGrandparent(k);
    if(p != NULL && g != NULL){ 
    if(k == p->right && p == g->left){
      rotateLeft(p);
      k = k->left;

    }
    
    
    else if(k == p->left && p == g->right){
      rotateRight(p);
      k = k->right;

    }
    }

    step2(k);

    
  }
  
  




}


void step2(node* k){
  
   node* p = k->parent;
   node* g = getGrandparent(k);
   if( p != NULL && g != NULL){   
    if(k == p->left){
     rotateRight(g);


   }
   
   else{
     rotateLeft(g);

   }
   p->color = 'b';
   g->color = 'r';

  }


}

void insertFix(node* k, node* &root){
  insert(k, root, root);
  fix(root, k);
  root = k;
  while(root->parent != NULL){
    root = root->parent;
  }



}


node* getUncle(node* root, node* k){

  node* p = k->parent;
  return getSibiling(root, p);



}
node* getSibiling(node* root, node* k){
  node* p = new node;
  if(k != NULL){
  p = k->parent;
  }
  if(p==NULL){
    return NULL;
  }
  if(k==p->left){
    return p->right; 
  }
  else{
    return p->left;
  }

}
node* getGrandparent(node* k){
  if(k == NULL){
    return NULL;

  }
  node* p = k->parent;
  if(p == NULL){
    return NULL;
  }
  node* t = p->parent;
  if(t == NULL){
    return NULL;
  }
  else{
    return t;
  }

}
void rotateLeft(node* k){
  if(k != NULL){
  node* temp = k->right;
  node* p = k->parent;
  assert(temp != NULL);
  
  k->right = temp->left;
  temp->left = k;
  k->parent = temp;
  if(k->right !=NULL){
    k->right->parent = k;
 

  }
  //if k was root
  if(p != NULL){
    if(k==p->left){
      p->left = temp;

    }
    else if(k==p->right){
      p->right = temp;

    }



  }
  temp->parent = p;
  }
  //cout<<"r"<<endl;
}
void rotateRight(node* k){
  node* temp = k->left;
  node* p = k->parent;
  assert(temp != NULL);

  k->left = temp->right;
  temp->right = k;
  k->parent = temp;
  if(k->left !=NULL){
    k->left->parent = k;
 

  }
  //if k was root
  if(p != NULL){
    if(k==p->left){
      p->left = temp;

    }
    else if(k==p->right){
      p->right = temp;

    }



  }
  temp->parent = p;
  
}
void print(node* current, int space){ //this method is taken from "Geeks for Geeks" https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
   if(current == NULL){
    return;
  }

  space += 10;
  
  print(current->right, space);
  cout<<endl;
  for (int i = 10; i < space; i++){  
    cout<<" ";
    }
  if(current->color == 'b'){
    cout<<current->value<<"b"<<"\n";  
     print(current->left, space); 
  }
  if(current->color == 'r'){
    cout<<current->value<<"r"<<"\n";  
     print(current->left, space); 
  }

}
void add(int x, node* &root){
  node* k = new node;
  k->value = x;
  insertFix(k, root);


}

void ReplaceNode(node*k, node* child){
  child->parent = k->parent;
  if(k==k->parent->left){
    k->parent->left = child;
  }
  else{
    k->parent->right = child;

  }

}
void deleteChild(node* root, node* k){
  node* child = (k->right == NULL) ? k->left : k->right; //child is whichevre child is not NULL
  assert(child);
  ReplaceNode(k, child);
  if(k->color == 'b'){
    if(child->color == 'r'){
      child->color = 'b';

    }
    else{
      deleteCase1(root, k); 

    }


  }



}
void deleteLeaf(int key, node* &current, node* &root){ //deletes an element
  //node is leaf
  //search to establish if in tree
  if(current == NULL){
    cout<<"No such element exists in the tree"<<endl;
    return;
  }
  
  if(key == current->value){
    if(current == root){ //what to do if root must be deleted
      if(current->left == NULL && current->right == NULL){ //lone root
       current = NULL;

     }
      else if(current->left == NULL && current->right != NULL){ //if only has left or right
       root->value = current->right->value;
       current->right = NULL;
     }
     else if(current->right == NULL && current->left != NULL){
       root->value = current->left->value;
       current->left = NULL;
     }
     else if(current->right != NULL && current->left != NULL){ //if it has both
       node* k = new node;
       k = root;
       root->value = findInorderSuccesor(root)->value; 
       deleteInorderSuccesor(k);
       
     }



   }
    else{
    //located node
    if(current->right == NULL && current->left == NULL){ //if leafe delete
      //cout<<"leaf"<<endl;
      //delete (current);
      current = NULL;
    }
    else if(current->right == NULL && current->left != NULL){ //only has left child
      current->value = current->left->value;
      current->left = NULL;
    }
    else if(current->left == NULL && current->right != NULL){ //only has right child
      current->value = current->right->value;
      current->right = NULL;

    }
    else if(current->right != NULL && current->left != NULL){
    //if has two children find inorder succesor, copy value, delete successor
      node* k = new node;
       k = current;
       current->value = findInorderSuccesor(current)->value; 
       deleteInorderSuccesor(k);
      
      
    
    }






    }



  }
  else{
    //cout<<findInorderSuccesor(current)->value<<endl;
    if(key > current->value){
      deleteLeaf(key, current->right, root);
    }
    if(key < current->value){
      deleteLeaf(key, current->left, root);
    }
  }

}



node* findInorderSuccesor(node* c){ //finds the succesor in order of node to be deleted
  if(c->right == NULL){
    return c;
  }
  findInorderSuccesor(c->right);
  
}

void deleteInorderSuccesor(node* &c){ //finds and deletes the inorder succesor, called after copying value
  if(c->right == NULL){
    c = NULL;
    return;
  }
  deleteInorderSuccesor(c->right);

}







    

void deleteCase1(node* root, node* k){
  if(k->parent != NULL){
    deleteCase2(root, k);
  }


}
void deleteCase2(node* root, node* k){
  node* s = getSibiling(root, k);
  if(s != NULL){ 
  if(s->color == 'r'){
    k->parent->color = 'r';
    s->color = 'b';
    if(k == k->parent->left){
      rotateLeft(k->parent);

    }
    else{
      rotateRight(k->parent);

    }

  }
  deleteCase3(root, k);
  }
}


void deleteCase3(node* root, node* k){
  node* s = getSibiling(root, k);
  if(s!= NULL){
  if((k->parent->color == 'b') && (s->color == 'b') && (s->left->color == 'b') && (s->right->color == 'b')){
    s->color = 'r';
    deleteCase1(root, k);

  }
  else{
    deleteCase4(root, k);
    
  }


  }

}



void deleteCase4(node* root, node* k){
  node* s = getSibiling(root, k);
  if( s!= NULL){
    if((k->parent->color = 'r') && (s->color == 'b') && (s->left->color == 'b') && (s->right->color == 'b')){
    s->color = 'r';
    k->parent->color = 'b';
  }
    else{
      deleteCase5(root, k);

    }


  }
  


}

void deleteCase5(node* root, node* k){
  node* s = getSibiling(root, k);
  //this code sets up case 6 to execute correctly
  if(s != NULL){
  if(s->color == 'b'){
    if((k == k->parent->left) && (s->right->color == 'b') && (s->left->color == 'r')){
      s->color = 'r';
      s->left->color = 'b';
      rotateRight(s);
    }
  }
  deleteCase6(root, k);



    }





  }
  




void deleteCase6(node* root, node*k){
  node* s = getSibiling(root, k);
  if(s != NULL){
    s->color = k->parent->color;
    k->parent->color = 'b';

    if((k == k->parent->left)){
	s->right->color = 'b';
	rotateLeft(k->parent);



      }
      else{
	s->left->color = 'b';
	rotateRight(k->parent);


      }

	





    
  }
}

void search(int key, node* current){
  if(current == NULL){
    cout<<"No such element exists in the tree"<<endl;
    return;

  }
 if(key == current->value){
    cout<<"The searched number exists in the tree"<<endl;
  }
  else{
    if(key > current->value){          //uses right more than/left less than property of tree to recursively search
      search(key, current->right);
    }
    if(key < current->value){
      search(key, current->left);
    }
  }
  


  
}  
  








void deleteNode(int key, node* current, node* root){
 if(current == NULL){
    cout<<"No such element exists in the tree"<<endl;
    return;

  }
 if(key == current->value){
   if(current->right == NULL && current->left != NULL){
     deleteChild(root, current);
   }
   else if(current->left == NULL && current->right != NULL){
      deleteChild(root, current);
   }
   else{
     deleteLeaf(key, current, root);

   }

   
   
  }
  else{
    if(key > current->value){          //uses right more than/left less than property of tree to recursively search
      deleteNode(key, current->right, root);
    }
    if(key < current->value){
      deleteNode(key, current->left, root);
    }
  }
  


  
} 





