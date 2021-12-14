/** @file Enemy.cpp
 *
 *  @brief File where Enemy methods are defined.
 *
 *  @author Jacob Holmes
 *  @bug No known bugs.
 */

#include "Enemy.h"

/** @brief Default Constructor.
 *
 *  Default constructor for the enemy class. It is overloaded (LO1b). It also
 * uses an initialization list (LO1c). When declaring the constructor as
 * noexcept, a new warning appears stating that the "function calls 'allocator<char>'
 * which may throw exceptions." I decided to not put the noexcept.
 *
 *  @return Constructors do not return anything.
 */
Enemy::Enemy() : sound("*silence*"), attack(1) {}

/** @brief Overloaded constructor.
 *
 *  This is another constructor that is overloaded (LO1b). It sets the enemy
 * specifics at creation of the object.
 *
 *  @param float h; variable for enemy health
 *  @param int a; variable for enemy attack
 *  @param string n; enemy name
 *  @param string s; enemy sound
 *  @return Constructors do not return anything
 */
Enemy::Enemy(float h, int a, std::string n, std::string s) {
  Character::set_health(h);
  attack = a;
  Character::set_name(n);
  sound = s;
}

/** @brief Gets enemy sound.
 *
 *  @return string; sound is a string.
 */
auto Enemy::getsound() -> std::string { return sound; }

/** @brief Gets enemy attack.
 *
 *  @return int; enemy's attack is an int.
 */
auto Enemy::get_attack() const noexcept -> int { return attack; }

/** @brief Damages the enemy.
 *
 *  This function allows us to damage the enemy. It also takes a function as an
 * argument (LO7). Source:
 * https://www.geeksforgeeks.org/passing-a-function-as-a-parameter-in-cpp/
 *
 *  @param float h; health of the enemy.
 *  @param float a; attack to be subtracted from health.
 *  @param function dmg; a function for subtracting attack from health
 *
 *  @return void
 */
void Enemy::take_damage(float h, float a,
                        std::function<float(float, float)> dmg) {
  float tempHealth = 0;
  tempHealth = dmg(h, a);
  Character::set_health(tempHealth);
}

/** @brief Simple function to demonstrate polymorphism.
 *
 *  This function demonstrates polymorphism (LO3). It overrides Characters kill
 * function. In the main file, it is called using the base class.
 *
 *  @return void
 */
void Enemy::kill() {
  std::cout << "All the enemies are dying! " << sound << std::endl;
}