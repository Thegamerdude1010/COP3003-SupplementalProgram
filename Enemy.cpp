#include "Enemy.h"

Enemy::Enemy() : sound("*silence*") {}

Enemy::Enemy(int h, int a, string n, string s) {
  health = h;
  attack = a;
  name = n;
  sound = s;
}

string Enemy::getsound() { return sound; }