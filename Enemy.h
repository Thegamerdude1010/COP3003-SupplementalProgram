#pragma once
#include "Character.h"
#include <functional>

class Enemy : public Character {
 private:
  // Private because nothing else shoud access it.
  string sound;

  // The enemy will only have a whole number attack, so int is used.
  int attack;

 public:
  Enemy();
  Enemy(float h, int a, string n, string s);
  
  string getsound();
  int get_attack();

  // Accepts a function as a parameter
  void take_damage(float, float, function<float(float,float)>);
  
  void kill();
};
