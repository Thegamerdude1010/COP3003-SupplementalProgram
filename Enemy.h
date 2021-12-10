#ifndef ENEMY_H
#define ENEMY_H

/** @file Enemy.h
 *
 *  @brief Header file for enemy class.
 *
 *  @author Jacob Holmes
 *  @bug No known bugs.
 */

#include <functional>

#include "Character.h"

/**
 * @brief This class is a subclass of character, meeting LO2.
 *
 * (LO2a) The Enemy class inherits the Character class publicly for simplicity.
 * Only public members are visible.
 */
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

  /**
   * @brief LO7, accepts function as parameter
   */
  void take_damage(float, float, std::function<float(float, float)>);

  void kill() override;
};

#endif