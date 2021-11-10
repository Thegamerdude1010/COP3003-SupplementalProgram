#include "Enemy.h"

Enemy::Enemy() : sound("*silence*") {}

Enemy::Enemy(int h, int a, string n, string s) {}

string Enemy::getsound() { return sound; }