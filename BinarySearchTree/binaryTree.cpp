//Dhruva Sogal Binary Tree Project Started 3/5/2020. This program reads in an input and constructs a binary search tree
//The tree can be searched, elements can be deleted and the tree can be printed
#include<iostream>
#include<fstream>
using namespace std;
struct node{
  node* left;
  node* right;
  int value;

};
void insert(int a , node* current, node* &root);
void read(node* &root);
void print(node* current, int space);
void search(int key, node* current);
void deleteLeaf(int key, node* &current, node* &root);
node* findInorderSuccesor(node* c);
void deleteInorderSuccesor(node* &c);
int main(){
  
  cout<<"This Program Creates a Binary Search Tree"<<endl;
  bool running = true;
  node* root = new node;
  root = NULL;        //0 used if node is empty as input must me 1 to 1000
  
  while(running == true){
    cout<<"Type 1 to read, 2 to print, 3 to delete, 4 to search, or 5 to quit"<<endl;

    int command = 0;
    cin>>command;
    if(command == 1){
      read(root);
    }
    if(command == 2){
      print(root, 0);
    }
    if(command ==3){
      cout<<"enter the number you wish to delete"<<endl;
      int k;
      cin>>k;
      deleteLeaf(k, root, root);
    }
    if(command == 4){
      cout<<"enter the number you wish to seach for"<<endl;
      int k;
      cin>>k;
      search(k, root);
      
    }
    if(command==5){
      running =false;
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
      insert(a, root, root);   
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
      insert(a, root, root);
      }
    }
  }
}//end read method
void insert(int a , node* current, node* &root){ //inserts elements appropriately into tree
  //cout<<a<<endl;
  if(root == NULL){ //if first node in tree
    cout<<"new root: "<<a<<endl;
    node* temp = new node;
    temp->value = a;
    root = temp;
    
  }
  else{
    if(a < current->value){
      if(current->left == NULL){
      node* temp = new node;
      temp->value = a;
      current->left = temp;
      }
      else{
	insert(a, current->left, root);
      }

    }
    else if(a > current->value){ //a is more than or equal to
      if(current->right == NULL){
      node* temp = new node;
      temp->value = a;
      current->right = temp;
      }
      else{
	insert(a, current->right, root);
      }



    }







  }
  
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
    cout<<current->value<<"\n";  
    print(current->left, space); 


}
void search(int key, node* current){ //searches tree
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


