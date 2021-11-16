#pragma once
#include <iostream>
#include <string>
using namespace std;

class Character {
  // All characters will have a health stat and a name. They are set
  // as protected so subclasses can use them, but other functions or classes can
  // not.
 protected:
  float health;
  string name;

 public:
  Character();
  float get_health();
  //int getattack();
  string get_name();

  void set_health(float h);
  void set_name(string n);

  
  virtual void take_damage();
};
