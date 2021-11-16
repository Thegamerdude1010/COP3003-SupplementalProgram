#pragma once
#include "Character.h"

class Player : public Character {
 private:
  string battle_cry;

 public:
  Player();
  Player(string n, string s);

  // I removed this get function becuase the friend function does its job.
  // string getsound();

  // This is a friend class. Designating a function as friend allows it to use
  // the private members of a class. In this case, it takes a player object and
  // prints the sound.
  friend void battle_cry(Player);
};
