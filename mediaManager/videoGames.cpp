//Dhruva Sogal completed 11/13/2019
#include<iostream>
using namespace std;
#include "media.h"
#include "videoGames.h"
//construcotr
videoGames :: videoGames(){
  publisher = new char;
  cout<<"Enter publisher name"<<endl;
  cin.ignore();
  cin.getline(publisher,90);
  cout<<"Enter rating"<<endl;
  cin>>rating;



}
//functions to return fields
int videoGames:: getRating(){
  return rating;
}
int videoGames::getType(){
  return 3;
}
char* videoGames::getPublisher(){
  return publisher;
}
//overwriting display
void videoGames::display(){
  cout<<"Title: "<<title<<endl;
  cout<<"Year: "<<year<<endl;
  cout<<"Publisher: "<<publisher<<endl;
  cout<<"Rating: "<<rating<<endl;

}
//destructor
videoGames::~videoGames(){
  delete(publisher);



}
