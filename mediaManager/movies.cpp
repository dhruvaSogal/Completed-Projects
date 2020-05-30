//movies class
//Dhruva Sogal completed 11/13/2019
#include<iostream>
#include "media.h"
#include "movies.h"
using namespace std;
movies :: movies(){ //constrcutor
  director = new char;
  cout<<"Enter the director's name"<<endl;
  cin.ignore();
  cin.getline(director,90);
  cout<<"Enter the duration"<<endl;
  cin>>duration;
  cout<<"Enter the movie's rating"<<endl;
  cin>>rating;
  
			      

}
//functions to get fields
int movies :: getType(){
  return 1;


}
char* movies :: getDirector(){
  return director;



}
float movies :: getDuration(){
  return duration;



}
float movies :: getRating(){
  return rating;



}
//overwriting display functions
void movies :: display(){
  cout<<"Title: "<<title<<endl;
  cout<<"Year: "<<year<<endl;
  cout<<"Director: "<<director<<endl;
  cout<<"Duration: "<<duration<<endl;
  cout<<"Rating: "<<rating<<endl;
  






}
movies :: ~movies(){ //dstrctr
  delete (director);


}


