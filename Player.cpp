/** @file Player.cpp
 *
 *  @brief File where player methods are defined.
 *
 *  @author Jacob Holmes
 *  @bug No known bugs.
 */

#include "Player.h"

/** @brief Short description of function.
 *
 *  Longer description of function.
 *
 *  @param One for each parameter with the name and a description
 *  @return The word void or a description of what is returned
 */
// This is called an initialization list. In this case, it is included as part
// of the default constructor.
Player::Player() : battle_cry("*silence*"), attack(1) {}

/** @brief Short description of function.
 *
 *  Longer description of function.
 *
 *  @param One for each parameter with the name and a description
 *  @return The word void or a description of what is returned
 */
Player::Player(std::string n, std::string s) {
  Character::set_health(startHealth);
  attack = startAttack;
  Character::set_name(n);
  battle_cry = s;
}

/** @brief Short description of function.
 *
 *  Longer description of function.
 *
 *  @param One for each parameter with the name and a description
 *  @return The word void or a description of what is returned
 */
float Player::get_attack() { return attack; }

/** @brief Short description of function.
 *
 *  Longer description of function.
 *
 *  @param One for each parameter with the name and a description
 *  @return The word void or a description of what is returned
 */
void Player::set_attack(float a) {
  if (a <= maxChargeAttack && a >= 0) {
    attack = a;
  } else {
    throw 1;
  }
}

/** @brief Short description of function.
 *
 *  Longer description of function.
 *
 *  @param One for each parameter with the name and a description
 *  @return The word void or a description of what is returned
 */
void Player::take_damage(float a) {
  float h = 0;
  h = Character::get_health();
  h -= a;
  Character::set_health(h);
}