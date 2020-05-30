//DHRUVA SOGAL Classes Project finished 11/13/2019
/*This is a media database that can add, search, and delete music, movies, and video games.
 */


#include<iostream>
#include "media.h"
#include"movies.h"
#include "music.h"
#include "videoGames.h"
#include<vector>
#include<cstring>
using namespace std;
void add(vector<media*>* items); //add method
void search(vector<media*>* items); //search method
void deleteMedia(vector<media*>* items); //delete method
int main(){
  bool running = true;
  char command[90];
  vector<media*>* items = new vector <media*>();
  while(running==true){ //while loop that takes in input and executes the program
    cout<<"Enter a Command, ADD to add, SRCH to search, DEL to delete, or QUIT to quit"
	<<endl;
    cin.getline(command, 90);
    if(strcmp(command, "ADD")==0){
      add(items);

    }
    if(strcmp(command, "SRCH")==0){
      search(items);

    }
    if(strcmp(command, "DEL")==0){
      deleteMedia(items);

    }
    if(strcmp(command, "QUIT")==0){
      running = false;

    }
  
  }



}
void add(vector<media*>* items){ 
  int child=0;
  cout<<"Enter 1 for movie, 2 for music, or 3 for video game"<<endl;
  cin>>child;
  if(child==1){ //if movie
    movies* movie = new movies(); //makes the movie
    items->push_back(movie); //adds to vector
  }
  if(child==2){ //if music
    music* song = new music();
  items->push_back(song);

  }
  if(child==3){ //if game
    videoGames* game = new videoGames();
    items->push_back(game);
  }
  
  cout<<"Added Media"<<endl;
}
void search(vector<media*>* items){ //search
  char type;
  cout<<"Enter 'y' for search by year or 't' for search by title"<<endl;
  cin>>type;
  if(type == 'y'){
    int yearSrch =0;
    cout<<"Enter year of release"<<endl;
    cin>>yearSrch;
    for(int i =0; i<items->size();i++){
      if(yearSrch == (*items)[i]->getYear()){
	cout<<   "FOUND:" <<endl;
	if((*items)[i]->getType()==1){
	  cout<<"Movie: "<<endl;
	}
	if((*items)[i]->getType()==2){
	  cout<<"Music: "<<endl;
	}
	if((*items)[i]->getType()==3){
	  cout<<"Video Game: "<<endl;
	}
	(*items)[i]->display();
	

      }
      


    }






  }

  if(type=='t'){
    char titleSrch [90];
    cout<<"Enter the title of the media"<<endl;
    cin.ignore();
    cin.getline(titleSrch, 90);
    for(int i =0; i< items->size(); i++){
      if(strcmp(titleSrch, (*items)[i]->getTitle())==0){
	cout<<"FOUND:"<<endl;
	if((*items)[i]->getType()==1){
	  cout<<"Movie: "<<endl;
	}
	if((*items)[i]->getType()==2){
	  cout<<"Music: "<<endl;
	}
	if((*items)[i]->getType()==3){
	  cout<<"Video Game: "<<endl;
	}
	(*items)[i]->display();

      }
    }

  }
  
  
  







}






void deleteMedia(vector<media*>* items){
  int size  = items->size(); //a new int because this method does change the size of the vector
   char type;
  cout<<"Enter 'y' for search by year or 't' for search by title"<<endl;
  cin>>type;
  if(type=='y'){
    cout<<"Enter Year of Release"<<endl;
    int yearSrch=0;
      cin>>yearSrch;
  for(int i =0; i<size;i++){
    if((*items)[i]->getYear()==yearSrch){
      cout<<"found: "<<endl;
      if((*items)[i]->getType()==1){
	cout<<"movie:"<<endl;
      }
      if((*items)[i]->getType()==2){
	cout<<"music:"<<endl;
      }
      if((*items)[i]->getType()==3){
	cout<<"video game:"<<endl;
      }





      
      
      (*items)[i]->display();
      char deleteMedia; //confirmation mechanism
      cout<<"do you wish to delete this, enter y if you do or anything else if you don't?"<<endl;
      cin>>deleteMedia;
      if(deleteMedia == 'y'){
	delete((*items)[i]);
	items->erase(items->begin()+i);
	i = size;


      }
	
    }


  }//end of for


  }//end if 
  //if search by title
  if(type=='t'){
    cout<<"Enter Title"<<endl;
    char titleSrch[90];
    cin.ignore();
    cin.get(titleSrch, 90);
  for(int i =0; i<size;i++){
    if(strcmp(titleSrch, (*items)[i]->getTitle())==0){
      cout<<"found: "<<endl;
	 if((*items)[i]->getType()==1){
	cout<<"movie:"<<endl;
      }
      if((*items)[i]->getType()==2){
	cout<<"music:"<<endl;
      }
      if((*items)[i]->getType()==3){
	cout<<"video game:"<<endl;
      }
      (*items)[i]->display();
      char deleteMedia;
      cout<<"do you wish to delete this?, enter y if you do or anything else if you don't"<<endl;
      cin>>deleteMedia;
      if(deleteMedia == 'y'){
	delete((*items)[i]);
	items->erase(items->begin()+i);
	i = size;


      }
	
    }


  }//end of for


  }//end if 

}









