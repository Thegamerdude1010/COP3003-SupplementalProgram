#pragma once
#include <iostream>
#include <string>
using namespace std;

class Character {
  // All characters will have a health stat and a name. They are set
  // as protected so subclasses can use them, but other functions or classes can
  // not.
 private:
  float healthDefault = 10;
  float health;
  string name;

 protected:
  ~Character();

 public:
  Character();
  float get_health();
  string get_name();

  void set_health(float h);
  void set_name(string n);

  
  virtual void take_damage();
  virtual void kill();
};
