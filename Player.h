#pragma once
#include "Character.h"
class Player : public Character {
 private:
  string sound;

 public:
  Player();
  Player(int h, int a, string n, string s);
  string getsound();
};
