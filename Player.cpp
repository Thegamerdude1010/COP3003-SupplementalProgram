/** @file Player.cpp
 *
 *  @brief File where player methods are defined.
 *
 *  @author Jacob Holmes
 *  @bug No known bugs.
 */

#include "Player.h"

/** @brief Default constructor.
 *
 *  Default constructor for the player class. It is overloaded (LO1b). It also
 * uses an initialization list (LO1c). This constructor has the same issue as
 * the constructor in Enemy.cpp, saying that the function should not be declared
 * noexcept. I am leaving out the noexcept.
 *
 *  @return Constructors do not return anything
 */
Player::Player() : battle_cry("*silence*"), attack(1) {}

/** @brief Overloaded Constructor.
 *
 *  This is another constructor that is overloaded (LO1b). It sets the player
 * specifics at creation of the object.
 *
 *  @param string n; string for the name of the player
 *  @param string s; string for the battle cry
 *  @return Constructors do not return anything
 */
Player::Player(std::string n, std::string s) {
  Character::set_health(startHealth);
  attack = startAttack;
  Character::set_name(n);
  battle_cry = s;
}

/** @brief Gets the player attack.
 *
 *  @return float; attack is a float.
 */
auto Player::get_attack() const noexcept -> float { return attack; }

/** @brief Sets player attack.
 *
 *  This allows us to change the player's attack. It is used in the main program
 * to set a charge attack. If the user enters more than the maxChargeAttack,
 * which is 100, it throws an int that is caught in the main file.
 *
 *  @param float a; new attack value
 *  @return void
 */
void Player::set_attack(float a) {
  if (a <= maxChargeAttack && a >= 0) {
    attack = a;
  } else {
    throw 1;
  }
}

/** @brief Lets player take damage.
 *
 *  This function allows the player to take damage. Takes the attack value off
 * of the health.
 *
 *  @param Ofloat a; attack of the enemy
 *  @return void
 */
void Player::take_damage(float a) noexcept {
  float h = 0;
  h = Character::get_health();
  h -= a;
  Character::set_health(h);
}