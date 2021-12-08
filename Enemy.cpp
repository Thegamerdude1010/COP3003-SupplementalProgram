/** @file Enemy.cpp
 *
 *  @brief File where enemy methods are defined.
 *
 *  @author Jacob Holmes
 *  @bug No known bugs.
 */

#include "Enemy.h"

/** @brief Short description of function.
 *
 *  Longer description of function.
 *
 *  @param One for each parameter with the name and a description
 *  @return The word void or a description of what is returned
 */
// This is called an initialization list. In this case, it is included as part
// of the default constructor.
Enemy::Enemy() : sound("*silence*"), attack(1) {}

/** @brief Short description of function.
 *
 *  Longer description of function.
 *
 *  @param One for each parameter with the name and a description
 *  @return The word void or a description of what is returned
 */
Enemy::Enemy(float h, int a, std::string n, std::string s) {
  Character::set_health(h);
  attack = a;
  Character::set_name(n);
  sound = s;
}

/** @brief Short description of function.
 *
 *  Longer description of function.
 *
 *  @param One for each parameter with the name and a description
 *  @return The word void or a description of what is returned
 */
auto Enemy::getsound() -> std::string { return sound; }

/** @brief Short description of function.
 *
 *  Longer description of function.
 *
 *  @param One for each parameter with the name and a description
 *  @return The word void or a description of what is returned
 */
auto Enemy::get_attack() -> int { return attack; }

/** @brief Short description of function.
 *
 *  Longer description of function.
 *
 *  @param One for each parameter with the name and a description
 *  @return The word void or a description of what is returned
 */
void Enemy::take_damage(float h, float a,
                        std::function<float(float, float)> dmg) {
  float tempHealth = 0;
  tempHealth = dmg(h, a);
  Character::set_health(tempHealth);
}

/** @brief Short description of function.
 *
 *  Longer description of function.
 *
 *  @param One for each parameter with the name and a description
 *  @return The word void or a description of what is returned
 */
void Enemy::kill() {
  std::cout << "All the enemies are dying! " << sound << std::endl;
}