/** @file Character.h

 *  @brief Brief description of file.

 *

 *  Longer description of file.

 *

 *  @author Jacob Holmes

 *  @bug No known bugs.

 */

// ifndef gotten from professor
#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>

class Character {
  // All characters will have a health stat and a name. They are set
  // as protected so subclasses can use them, but other functions or classes can
  // not.
 private:
  float healthDefault = 10;
  float health;
  std::string name;

 protected:
  ~Character();

 public:
  Character();
  auto get_health() -> float;
  auto get_name() -> std::string;

  void set_health(float h);
  void set_name(std::string n);

  
  virtual void take_damage();
  virtual void kill();
};

#endif