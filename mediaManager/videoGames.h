//Dhruva Sogal completed 11/13/2019
//this is a videoGames class that contains fields for publisher and rating
#include<iostream>
class videoGames: public media{
private:
  char* publisher;
  float rating;
public:
  videoGames();
 ~videoGames();
  char* getPublisher();
  int getRating();
  int getType();
  void display();
};

