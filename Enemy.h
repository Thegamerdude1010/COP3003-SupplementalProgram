/** @file Enemy.h

 *  @brief Brief description of file.

 *

 *  Longer description of file.

 *

 *  @author Jacob Holmes

 *  @bug No known bugs.

 */

#pragma once
#include "Character.h"
#include <functional>

class Enemy : public Character {
 private:
  // Private because nothing else shoud access it.
  std::string sound;

  // The enemy will only have a whole number attack, so int is used.
  int attack;

 public:
  Enemy();
  Enemy(float h, int a, std::string n, std::string s);
  
  auto getsound() -> std::string;
  auto get_attack() -> int;

  // Accepts a function as a parameter
  void take_damage(float, float, std::function<float(float,float)>);
  
  void kill();
};
