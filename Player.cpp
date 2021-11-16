#include "Player.h"

// This is called an initialization list. In this case, it is included as part
// of the default constructor.
Player::Player() : battle_cry("*silence*"), attack(1) {}

Player::Player(string n, string s) {
  health = 10;
  attack = 5;
  name = n;
  battle_cry = s;
}

float Player::get_attack() { return attack; }

void Player::set_attack(float a) {
  if (a <= 100 && a >= 0) {
    attack = a;
  } else {
    throw 1;
  }
}

void Player::take_damage(int a) { health -= a; }