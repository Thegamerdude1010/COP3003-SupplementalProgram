#include "Player.h"

Player::Player() : battle_cry("*silence*") {}

Player::Player(string n, string s) {
  health = 10;
  attack = 1;
  name = n;
  battle_cry = s;
}