/** @file Character.cpp
 *
 *  @brief File where character methods are defined.
 *
 *  @author Jacob Holmes
 *  @bug No known bugs.
 */

#include "Character.h"

/** @brief Short description of function.
 *
 *  Longer description of function.
 *
 *  @param One for each parameter with the name and a description
 *  @return The word void or a description of what is returned
 */
// This is called an initialization list. In this case, it is included as part
// of the default constructor.
Character::Character() : health(healthDefault), name("NoName") {}

/** @brief Short description of function.
 *
 *  Longer description of function.
 *
 *  @param One for each parameter with the name and a description
 *  @return The word void or a description of what is returned
 */
// Destructor was created to clear warnings.
Character::~Character() = default;

/** @brief Short description of function.
 *
 *  Longer description of function.
 *
 *  @param One for each parameter with the name and a description
 *  @return The word void or a description of what is returned
 */
auto Character::get_health() const -> float { return health; }

/** @brief Short description of function.
 *
 *  Longer description of function.
 *
 *  @param One for each parameter with the name and a description
 *  @return The word void or a description of what is returned
 */
auto Character::get_name() -> std::string { return name; }

/** @brief Short description of function.
 *
 *  Longer description of function.
 *
 *  @param One for each parameter with the name and a description
 *  @return The word void or a description of what is returned
 */
void Character::set_health(float h) { health = h; }

/** @brief Short description of function.
 *
 *  Longer description of function.
 *
 *  @param One for each parameter with the name and a description
 *  @return The word void or a description of what is returned
 */
void Character::set_name(std::string n) { name = n; }

/** @brief Short description of function.
 *
 *  Longer description of function.
 *
 *  @param One for each parameter with the name and a description
 *  @return The word void or a description of what is returned
 */
// This method will take 1 off of health just incase the method is not
// overridden.
void Character::take_damage() { health -= 1; }

/** @brief Short description of function.
 *
 *  Longer description of function.
 *
 *  @param One for each parameter with the name and a description
 *  @return The word void or a description of what is returned
 */
void Character::kill() {
  std::cout << "All the characters are dying" << std::endl;
}