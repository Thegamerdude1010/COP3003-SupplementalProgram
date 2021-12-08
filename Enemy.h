/** @file Enemy.h
 *
 *  @brief Header file for enemy class.
 *
 *  @author Jacob Holmes
 *  @bug No known bugs.
 */

#ifndef ENEMY_H
#define ENEMY_H

#include <functional>

#include "Character.h"

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
  auto get_attack() const -> int;

  // Accepts a function as a parameter
  void take_damage(float, float, std::function<float(float, float)>);

  void kill();
};

#endif