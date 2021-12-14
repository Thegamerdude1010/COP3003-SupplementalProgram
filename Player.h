#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
/** @file Player.h
 *
 *  @brief Header file for Player class.
 *
 *  @author Jacob Holmes
 *  @bug No known bugs.
 */

/**
 * @brief This class is a subclass of character, meeting LO2.
 *
 * (LO2a) The Player class inherits the Character class publicly for simplicity.
 * Only public members are visible.
 */
class Player : public Character {
 private:
  // Private because nothing else should access it.
  std::string battle_cry;

  // The player will have an attack with a decimal so I use float.
  float attack;
  const float startAttack = 5.0F;

  const float maxChargeAttack = 100.0F;
  const float startHealth = 10.0F;

 public:
  Player();
  Player(std::string n, std::string s);

  // I removed this get function becuase the friend function does its job.
  // string getsound();

  auto get_attack() const noexcept -> float;

  void set_attack(float a);

  /**
   * @brief This is a friend function.
   *
   * Designating a function as friend allows it to use the private members of a
   * class. In this case, it takes a player object and prints the sound.
   *
   */
  friend void battle_cry(Player);

  void take_damage(float a) noexcept;
};

#endif