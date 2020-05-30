//Dhruva Sogal finsihed 11/13/2019
//movies class that has title, year, director, and rating, and duration
#include<iostream>
class movies : public media{
public:
 movies();
 ~movies();
  int getType();
 float getRating();
  void display();
  float getDuration();
  char* getDirector();
private:
  char* director;
  float duration;
  float rating;
  
  




};

