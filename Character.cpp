#include "Character.h"

// This is called an initialization list. In this case, it is included as part
// of the default constructor.
Character::Character() : health(healthDefault), name("NoName") {}

// Destructor was created to clear warnings.
Character::~Character() { cout << "Destroyed" << endl; }

// If I use a trailing return type, I can't use constant.
auto Character::get_health() -> float { return health; }
auto Character::get_name() -> string { return name; }

void Character::set_health(float h) { health = h; }

void Character::set_name(string n) { name = n; }

// This method will take 1 off of health just incase the method is not
// overridden.
void Character::take_damage() { health -= 1; }

void Character::kill() { cout << "All the characters are dying" << endl; }