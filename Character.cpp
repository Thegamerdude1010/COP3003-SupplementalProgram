/** @file Character.cpp
 *
 *  @brief File where character methods are defined.
 *
 * This file completes the requirements for LO1a.
 *
 *  @author Jacob Holmes
 *  @bug No known bugs.
 */

#include "Character.h"

/** @brief Default Constructor.
 *
 *  Default constructor for the Character class. Uses an initialization list
 * (LO1c).
 *
 *  @return Constructors do not return anything.
 */
Character::Character() : health(healthDefault), name("NoName") {}

/** @brief Default destructor.
 *
 *  This destructor was added to clear warnings in the code.
 *
 *  @return Destructors do not return anything.
 */
Character::~Character() = default;

/** @brief Gets character health.
 *
 *  @return float; health is type float.
 */
auto Character::get_health() const -> float { return health; }

/** @brief Gets character name.
 *
 *  @return string; name is of type string.
 */
auto Character::get_name() -> std::string { return name; }

/** @brief Sets character health.
 *
 *  This function sets the health of a character. This allows us to change the
 * health while maintaining variables as private.
 *
 *  @param float h; a variable for the new health.
 *  @return void
 */
void Character::set_health(float h) { health = h; }

/** @brief Sets character name.
 *
 *  In the event that a character needs its name changed, this function could be
 * used. I did not use it in the main game, but it can be used.
 *
 *  @param string n; a string with the new name.
 *  @return void
 */
void Character::set_name(std::string n) { name = n; }

/** @brief Deals damage.
 *
 *  This is a virtual function that allows users to deal damage. It is
 * overridden in the subclasses, but it is defined here in case something goes
 * wrong.
 *
 *  @return void
 */
void Character::take_damage() { health -= 1; }

/** @brief SSimple function that prints to the console.
 *
 *  This function was added to demonstrate polymorphism. The subclass Enemy
 * overrides the function, which is then used in the main file to practice
 * polymorphism.
 *
 *  @return void
 */
void Character::kill() {
  std::cout << "All the characters are dying" << std::endl;
}