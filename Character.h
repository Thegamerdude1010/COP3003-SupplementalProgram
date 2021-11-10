#pragma once
#include <string>
#include <iostream>
using namespace std;

class Character {
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
