/** @file Enemy.cpp

 *  @brief Brief description of file.

 *

 *  Longer description of file.

 *

 *  @author Jacob Holmes

 *  @bug No known bugs.

 */

#include "Enemy.h"

// This is called an initialization list. In this case, it is included as part
// of the default constructor.
Enemy::Enemy() : sound("*silence*"), attack(1) {}

Enemy::Enemy(float h, int a, string n, string s) {
  Character::set_health(h);
  attack = a;
  Character::set_name(n);
  sound = s;
}

auto Enemy::getsound() -> string { return sound; }
auto Enemy::get_attack() -> int { return attack; }

void Enemy::take_damage(float h, float a, function<float(float, float)> dmg) {
  float tempHealth = 0;
  tempHealth = dmg(h, a);
  Character::set_health(tempHealth);
}

void Enemy::kill() { cout << "All the enemies are dying! " << sound << endl; }