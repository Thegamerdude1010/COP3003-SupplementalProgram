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
  float healthDefault = 10.0F;
  float health;
  std::string name;

 protected:
  /**
   * @brief Warning C26432 calls for using the rule of 5.
   *
   * When defining these constructors and operators, it clears the warning but
   * causes errors. So, I am leaving this warning because it breaks the code.
   * Source for warning:
   * https://docs.microsoft.com/en-us/cpp/code-quality/c26432?f1url=%3FappId%3DDev16IDEF1%26l%3DEN-US%26k%3Dk(C26432)%26rd%3Dtrue&view=msvc-170KD,
   *
   */
  ~Character();

 public:
  Character();

  auto get_health() const noexcept -> float;
  auto get_name() -> std::string;

  void set_health(float h) noexcept;
  void set_name(std::string n);

  virtual void take_damage() noexcept;
  virtual void kill();
};

#endif