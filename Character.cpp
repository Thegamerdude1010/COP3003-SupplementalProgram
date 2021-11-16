#include "Character.h"
#

Character::Character() : health(10), attack(1), name("NoName") {}

int Character::gethealth() { return health; }
int Character::getattack() { return attack; }
string Character::getname() { return name; }

void Character::sethealth(int h) { health = h; }
void Character::setattack(int a) {
  if (a <= 100 && a >= 0) {
    attack = a;
  } else {
    throw 1;
  }
}
void Character::setname(string n) { name = n; }