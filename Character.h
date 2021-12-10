#ifndef CHARACTER_H
#define CHARACTER_H
// ifndef gotten from professor

/** @file Character.h
 *
 *  @brief Header file for Character class. This file meets LO1 and LO1a.
 *
 *  @author Jacob Holmes
 *  @bug No known bugs.
 */

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
  auto get_health() const -> float;
  auto get_name() -> std::string;

  void set_health(float h);
  void set_name(std::string n);

  virtual void take_damage();
  virtual void kill();
};

#endif