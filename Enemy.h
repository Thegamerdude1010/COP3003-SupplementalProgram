#pragma once
#include "Character.h"

class Enemy : public Character {
 private:
  string sound;

 public:
  Enemy();
  Enemy(int h, int a, string n, string s);
  string getsound();
};
