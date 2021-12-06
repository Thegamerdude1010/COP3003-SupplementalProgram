#include "Player.h"

// This is called an initialization list. In this case, it is included as part
// of the default constructor.
Player::Player() : battle_cry("*silence*"), attack(1) {  }

Player::Player(string n, string s) {
  Character::set_health(10);
  attack = 5;
  Character::set_name(n);
  battle_cry = s;
}

float Player::get_attack() { return attack; }

void Player::set_attack(float a) {
  if (a <= maxChargeAttack && a >= 0) {
    attack = a;
  } else {
    throw 1;
  }
}

void Player::take_damage(float a) {
  float h;
  h = Character::get_health();
  h -= a;
  Character::set_health(h);
}