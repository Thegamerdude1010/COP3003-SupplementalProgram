#include "Enemy.h"

// This is called an initialization list. In this case, it is included as part
// of the default constructor.
Enemy::Enemy() : sound("*silence*"), attack(1) {}

Enemy::Enemy(float h, int a, string n, string s) {
  health = h;
  attack = a;
  name = n;
  sound = s;
}

string Enemy::getsound() { return sound; }
int Enemy::get_attack() { return attack; }

void Enemy::take_damage(float h, float a, function<float(float,float)> dmg) { health = dmg(h,a); }



void Enemy::kill() { cout << "All the enemies are dying! " << sound << endl; }