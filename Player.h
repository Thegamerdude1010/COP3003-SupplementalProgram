#pragma once
#include "Character.h"

class Player : public Character {
 private:
  // Private because nothing else should access it.
  string battle_cry;

  // The player will have an attack with a decimal so I use float.
  float attack;

 public:
  Player();
  Player(string n, string s);

  // I removed this get function becuase the friend function does its job.
  // string getsound();

  float get_attack();

  void set_attack(float a);

  // This is a friend class. Designating a function as friend allows it to use
  // the private members of a class. In this case, it takes a player object and
  // prints the sound.
  friend void battle_cry(Player);

  void take_damage(int);
};
