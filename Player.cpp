#include "Player.h"

Player::Player() : sound("*silence*") {}

Player::Player(int h, int a, string n, string s) {
  health = h;
  attack = a;
  name = n;
  sound = s;
}

string Player::getsound() { return sound; }