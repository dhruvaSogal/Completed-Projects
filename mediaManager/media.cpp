//media class
//Dhruva Sogal finished 11/13/2019
#include<iostream>
#include "media.h"
#include "movies.h"
using namespace std;
media :: media(){
  title = new char;
  cout<<"Enter media title"<<endl;
  cin.ignore();
  cin.getline(title,90);
  cout<<"Enter year of release"<<endl;
  cin>>year;
  
  
  


}
//year and title for searching
int media::getYear()
{
  return year;
}
char* media::getTitle()
{
  return title;
  
  }
void media::display(){
  cout<<"mustard"<<endl;



}
int media:: getType(){


}
//destructor
media :: ~media(){
  delete (title);


}

