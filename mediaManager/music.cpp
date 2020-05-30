//Dhruva Sogal finished 11/13/2019
//music class

#include<iostream>
using namespace std;
#include "media.h"
#include "music.h"
//constructor
music :: music(){
  artist =  new char;
  publisher = new char;
  cout<<"Enter artist name"<<endl;
  cin.ignore();
  cin.getline(artist,90);
  cout<<"Enter publisher"<<endl;
  cin.ignore();
  cin.getline(publisher,90);
  cout<<"Enter duration"<<endl;
  cin>>duration;
			



}
//functions to return field
int music:: getType(){
  return 2;

}
float music :: getDuration(){
  return duration;


}
char* music:: getArtist(){
  return artist;


}
char* music::getPublisher(){
  return publisher;


}
//overwriting display function
void music:: display(){
  cout<<"Title: "<<title<<endl;
  cout<<"Year: "<<year<<endl;
  cout<<"Publisher: "<<publisher<<endl;
  cout<<"Duration: "<<duration<<endl;
  cout<<"Artist: "<<artist<<endl;





}
music :: ~music(){
  delete(artist);
  delete(publisher);

}



