#pragma once
#include <iostream>
#include <string>
using namespace std;

class Character {
  // All characters will have a health stat, an attack, and a name. They are set
  // as protected so subclasses can use them, but other functions or classes can
  // not.
 protected:
  int health;
  int attack;
  string name;

 public:
  Character();
  int gethealth();
  int getattack();
  string getname();

  void sethealth(int h);
  void setattack(int a);
  void setname(string n);
};
