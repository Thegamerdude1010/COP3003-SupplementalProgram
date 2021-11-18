#include "Character.h"

// This is called an initialization list. In this case, it is included as part
// of the default constructor.
Character::Character() : health(10), name("NoName") {}

float Character::get_health() { return health; }
string Character::get_name() { return name; }

void Character::set_health(float h) { health = h; }

void Character::set_name(string n) { name = n; }

// This method will take 1 off of health just incase the method is not
// overridden.
void Character::take_damage() { health -= 1; }

void Character::kill() { cout << "All the characters are dying" << endl; }