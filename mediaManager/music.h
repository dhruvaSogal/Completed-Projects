
#include<iostream>
class music: public media{
public:
  music();
  ~music();
  int getType();
  float getDuration();
  void display();
  char* getArtist();
  char* getPublisher();
  


private:
 char* artist;
 char* publisher;
 float duration;

};

