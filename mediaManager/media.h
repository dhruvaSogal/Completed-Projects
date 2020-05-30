//DHRUVA SOGAL completed 11/13/2019
//this is the media parent class its chidlren are movies, music, and videoGames

#ifndef MEDIA_H
#define MEDIA_H
#include<iostream>
class media{
public:
  media(); //constrcutor
  ~media();//destructor
  int getYear();
  char* getTitle();
  virtual void display(); //overwritten function
  virtual int getType();
protected:
  char* title;
  int year;



};
#endif
